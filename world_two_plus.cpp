#include <iostream>
#include <algorithm>
#define max_size 16
using namespace std;

int ans=0;

int myfinder(int x,int y,int k,char input_array[max_size][max_size],int n,int m);
void find_2_big(char input_array[max_size][max_size],int n,int m,int len){
	int i,j,k;
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			for (k=0;k<=min(i,j);k++){
				if (myfinder(i,j,k+1,input_array,n,m)){
					ans=max(ans,(len)*(4*k+1));
				}
			}
		}
	}
}

void runs(int x,int y,int k,char input_array[max_size][max_size],int n,int m)
{
	if (x<k-1 || y<k-1 ) return ;
	if (x+k-1>=n || y+k-1>=m) return ;
	int i,j;
	char b[max_size][max_size];
	for (i=0;i<n;i++) for (j=0;j<n;j++) b[i][j]=input_array[i][j];
	for (i=0;i<k;i++)
	{
		if (input_array[x-i][y]!='G')
		{
			return ;
		}
		else
		{
			b[x-i][y]='B';
		}
	}
	for (i=0;i<k;i++)
	{
		if (input_array[x+i][y]!='G')
		{
			return ;
		}
		else
		{
			b[x+i][y]='B';
		}
	}
	for (i=0;i<k;i++)
	{
		if (input_array[x][y-i]!='G')
		{
			return ;
		}
		else
		{
			b[x][y-i]='B';
		}
	}
	for (i=0;i<k;i++)
	{
		if (input_array[x][y+i]!='G')
		{
			return ;
		}
		else
		{
			b[x][y+i]='B';
		}
	}
	find_2_big(b,n,m,4*k-3);
}


void checK_for_biggest_plus(char input_array[max_size][max_size],int n,int m)
{
	int i,j,k;
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			for (k=0;k<=min(i,j);k++)
			{
				runs(i,j,k+1,input_array,n,m);
			}
		}
	}
}
int main()
{
	char input_array[max_size][max_size];
	long long int t,n,j,m;
	int i;
	t=1;
	for(int io=0;io<t;io++){
		cin>>n>>m;
		for (i=0;i<n;i++) 
			for (j=0;j<m;j++) cin>>input_array[i][j];
		bool flag =true;
		for(int p=0;p<n;p++){
			for(int q=0;q<m;q++){
				if(input_array[i][j]=='G'){
					flag=true;
					break;
				}
			}
			if(flag)
				break;
		}

		if(!flag)
			cout<<(0)<<endl;
		else{
			checK_for_biggest_plus(input_array,n,m);
			cout<<ans<<endl; 
		}
	}
	return 0;
}
int myfinder(int x,int y,int k,char input_array[max_size][max_size],int n,int m){
	int i;
	if (x<k-1 || y<k-1 ) return 0;
	if (x+k-1>=n || y+k-1>=m) return 0;
	for (i=0;i<k;i++)
	{
		if (input_array[x-i][y]!='G')
		{
			return 0;
		}
	}
	for (i=0;i<k;i++)
	{
		if (input_array[x+i][y]!='G')
		{
			return 0;
		}
	}
	for (i=0;i<k;i++)
	{
		if (input_array[x][y-i]!='G')
		{
			return 0;
		}
	}
	for (i=0;i<k;i++)
	{
		if (input_array[x][y+i]!='G')
		{
			return 0;
		}
	}
	return 1;
}
