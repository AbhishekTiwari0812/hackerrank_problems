#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <vector>
typedef long long int lli;
typedef long double ld;
using namespace std;

int main(){
	int n;
	int *A;
	cin>>n;
	A=new int[n];
	for(int i=0;i<n;i++)
		cin>>A[i];
	sort(A,A+n);
	int max=1;
	for(int i=0;i<n;i++){
		if(A[i] > max){
			max=A[i];
		}
		max++;
	}
	cout<<(max-1)<<endl;
	return 0;
}