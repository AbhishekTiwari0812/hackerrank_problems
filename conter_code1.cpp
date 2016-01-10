#include<iostream>
using namespace std;

typedef struct Soilders{
	int val=0;		//1 means counted,2 means can't take it,0 means nothing assigned
}soilders;

int main(){
	int N,k;
	static int count=0;
	cin>>N>>k;
	soilders *mSoil=new soilders[N];	
	int sniper;	
	for(int i=0;i<k;i++){
		cin>>sniper;
		mSoil[sniper].val=1;	
		count++;
		if(sniper-1>=0)	
			mSoil[sniper-1].val=2;
		if(sniper+1<N)
			mSoil[sniper+1].val=2;		
	}
	for(int i=0;i<N;i++){
		if(mSoil[i].val==0){
			count++;
			mSoil[i].val=1;
			if(i-1>=0)	
				mSoil[i-1].val=2;
			if(i+1<N)
				mSoil[i+1].val=2;
					
		}
	}
	cout<<count;

}
