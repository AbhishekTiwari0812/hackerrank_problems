#include <bits/stdc++.h>
#define f(i,a,b) for(int i=(a),__=(b); i < __; ++i)
#define fr(i,b,a) for(int i=(b), __ = ( a ); i >= __; --i)
#define pb push_back
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef set<string> ss;

string s1,s2;
int l1,l2;
int memo[5005][5005][2];


ll dp(int i,int j,int flag){
	if(s[i]==s[j]){
		
	}
}

void solve(){
	dp(0,0,0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>s1;
	cin>>s2;
	l1=s1.length();
	l2=s2.length();
	f(i,0,l1)
		f(j,0,l2)
			memo[i][j]=-1;
	solve();
	return 0;
}
