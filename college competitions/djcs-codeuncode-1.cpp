#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cmath>
#define MOD (int)(1e9+7)

typedef long long int lli;


using namespace std;
int n,m;
string *A;
int check(int x,int y){
	int count=0;
	if(x-1 >=0 && y-1 >=0)
		if(A[x-1][y-1]=='*')
			count++;
	if(y-1 >=0)
		if(A[x][y-1]=='*')
			count++;
	if(x+1<n && y-1 >=0)
		if(A[x+1][y-1]=='*')
			count++;
	if(x-1>=0)
		if(A[x-1][y]=='*')
			count++;
	if(x+1<n)
		if(A[x+1][y]=='*')
			count++;
	if(x-1 >=0 && y+1 <m)
		if(A[x-1][y+1]=='*')
			count++;
	if( y+1 < m)
		if(A[x][y+1]=='*')
			count++;
	if(x+1 <n  && y+1 <m)
		if(A[x+1][y+1]=='*')
			count++;
	return count;

}

int main(){

	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		A=new string[n];
		string s;
		for(int i=0;i<n;i++){
			cin>>s;
			A[i]=s;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<check(i,j);
			}
			cout<<endl;
		}

	}
	return 0;
}