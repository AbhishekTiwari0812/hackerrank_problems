#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <vector>
typedef long long int lli;
typedef long double ld;
using namespace std;

int main(){
	int test;
	cin>>test;
	for(int some=0;some<test;some++){
		int n;
		cin>>n;
		int temp;
		int count=0;
		int *A;
		A=new int[n];
		for(int i=0;i<n;i++)
			cin>>A[i];
		for(int i=n-1;i>=0;i--){
			if(A[i]!=i+1){
				if(A[i-1]==i+1){
					temp=A[i];
					A[i]=A[i-1];
					A[i-1]=temp;
					count++;
				}
				else if(A[i-2]==i+1){
					temp=A[i-2];
					A[i-2]=A[i-1];
					A[i-1]=temp;
					count++;
					temp=A[i];
					A[i]=A[i-1];
					A[i-1]=temp;
					count++;
				}
				else{
					cout<<"Too chaotic"<<endl;
					count=-1;
					break;
				}
			}
		}
		if(count!=-1){
			cout<<count<<endl;
		}

	}
	return 0;
		}

}