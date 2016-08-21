#include <bits/stdc++.h>
#define f(i,a,b) for(int i=(a),__=(b); i < __; ++i)
#define fr(i,b,a) for(int i=(b), __ = ( a ); i >= __; --i)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef set<string> ss;
const int size=2*(int)1e5+10;
int a[size];
int val[size];
int indices[size];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(val,0,sizeof(val));
	cin>>n;
	int sym,x;
	int current_index=size-1;
	f(i,0,n){
		cin>>sym>>x;
		if(sym=='+'){
			a[current_index]=x;
			if(a[indices[current_index+1]-1]==x){
				val[current_index]=val[current_index+1]+1;
				indices[current_index]=indices[current_index+1]-1;
			}
			else{
				int start_point = indices[current_index+1];	
			}
			
			current_index--;
		}
	}
	return 0;
}