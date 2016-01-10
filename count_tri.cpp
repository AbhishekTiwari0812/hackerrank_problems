#include <iostream>
#include <algorithm>
using namespace std;
int ACUTE;
int RIGHT;
int OBSTUSE;



int bin_search(int *A,int start,int end,int key){
	int mid=(start+end)/2;
	if(mid<end){
		if(A[mid]==key)
			return mid;
		else if(A[mid]>key)
			return bin_search(A,start,mid,key);
		else return bin_search(A,mid+1,end,key);
	
	}
	else return mid;
}


int *A;
int *B;

void count(int a,int b,int start,int end){
	if(start==end  &&  a+b<=A[start])
		return;
	//cout<<"a:"<<a<<" b:"<<b<<endl;
	int mid_index=bin_search(B,start,end,a*a+b*b);

	if (B[mid_index]==a*a+b*b){
		RIGHT+=1;
	//	cout<<"1 right,"<<mid_index-start<<" acute and "<<end- mid_index<< " obtuse"<<endl;
		ACUTE+=mid_index-start;
		OBSTUSE+=end- mid_index;
	}
	else{
		if(B[mid_index]  > a*a+b*b){
	//		cout<<mid_index-start<<" acute and "<<end- mid_index+1<< " obtuse.\n"<<endl;
			ACUTE+=mid_index-start;
			OBSTUSE+=end- mid_index+1;	
		}
		else{
	//		cout<<mid_index-start+1<<" acute and 0 obtuse.\n"<<endl;
			ACUTE+=mid_index-start+1;
		}
	}

}

int main(){
   	ACUTE=RIGHT=OBSTUSE=0;
    int N;
    cin >> N;
    A=new int[N];
    B=new int[N];
    for(int A_i = 0;A_i < N;A_i++){
       cin >> A[A_i];
       B[A_i]=A[A_i]*A[A_i];
    }
    int start_index;
    int end_index;
    for(int i=0;i<N-2;i++)
    	for(int j=i+1;j<N-1;j++){
    		start_index=j+1;
    		end_index=bin_search(A,0,N-1,A[j]+A[i]);
   			if(A[end_index]>=A[j]+A[i])
   				end_index-=1;

    		if(end_index  < start_index)
    			continue;
    		count(A[i],A[j],start_index,end_index);
    	}
    cout<<ACUTE<<" "<<RIGHT<< " "<<OBSTUSE<<endl;

    return 0;
}
