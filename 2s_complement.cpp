//incomplete
#include <climits>
#include <iostream>
using namespace std;
typedef long long int lli;

int count_ones(int n){
	if(n==0)
		return 0;
	else{
		return (n&1)+count_ones(n/2);
	}
}


lli *pos_vals;
int pos_size=40;
void cal_pos(){
	pos_vals[0]=0;
	pos_vals[1]=1;
	pos_vals[2]=2;
	for(int i=3;i<pos_size;i++){
		pos_vals[i]=(pos_vals[i-1]-pos_vals[i-1])*4+1;
	}	
}

void cal_neg(){

}


int main(){
	pos_vals=new lli[pos_size];
	cal_pos();
	int t;
	lli max=(long)INT_MAX+1;			//2 to power 32
	cin>>t;
	for(int i=0;i<t;i++){
		lli start=max-(1);
		lli end=max-(1<<i);
		lli num=0;
		cout<<max<<endl;
		cout<<end<<endl;
		for(int j=end;j<=start;j++){
			num+=count_ones(j);
		}
		cout<<"till-"<<(1<<i)<<":"<<num<<endl;
	}
	return 0;
}