#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define f(i,a,b) for( int i = ( a ), __ =(b); i < __; ++i )
#define fr(i,a,b) for( int i = ( a ), __= (b) ; i >= __; --i )
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int>ii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef set<int> si;
typedef set<string> ss;
typedef set<ll> sl;
typedef set<ld> sd;
typedef map<string,int> msi;
typedef map<string,ll> msl;
typedef map<string,ld> msd;
typedef map<string,string> mss;
typedef map<int,string> mis;
typedef map<ll,string> mls;
typedef map<ld,string> mds;
string a,b;
int l1,l2;

int dp[1002][1002];

bool solve(int i,int j){
	if(j>=l2 && i <= l1)
		return true;
	else if( i == l1 && j < l2){
		return false;
	}
	else if( dp[i][j]!=-1)
		return dp[i][j];
	if(a[i] == b[j] || a[i]-'a'+'A' == b[j]){
		bool a = solve(i+1,j+1);
		bool b = solve(i+1,j);
		dp[i][j] = a|b;
		return a|b;
	}
	else if(a[i] != b[j] && a[i] >='A' && a[i] <= 'Z')
		return false;
	else{
		dp[i][j] = solve(i+1,j);
		return dp[i][j];
	}
}

void init(){
	for(int i=0;i<l1;++i){
		for(int j=0;j<l2;++j)
			dp[i][j]=-1;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin>>q;
	while(q--){
		cin>>a>>b;
		l1 = a.length();
		l2 = b.length();
		init();
		bool flag = solve(0,0);
		if(flag)
			cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}