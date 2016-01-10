#include<iostream>
using namespace std;
int main(){
	int N;
	cin>>N;
	int A[N];	
	bool dies[N];
	static int days=1;
	for(int i=0;i<N;i++)
		cin>>A[i];
	int min=A[0];
	dies[0]=false;
	for(int i=1;i<N;i++){
		if(A[i]>min)
			dies[i]=true;
		else {
			dies[i]=false;
			min=A[i];			
		}
	}
	for(int i=0;i<N;i++){
		if(dies[i])
			if(A[i]<A[i-1])
				days++;
	}
	cout<<days<<endl;
	return 0;
}
