#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define f(i,a,b) for( int i = ( a ); i < (b); ++i )
#define fr(i,a,b) for( int i = ( a ); i >= ( b ); --i )
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

int a[256][256];
int gn;
ll solve(int i,int j){
	ll max = a[i][j];
	if(a[gn-i-1][j] >max)
		max	= a[gn-i-1][j];
	if(a[gn-i-1][gn-j-1] >  max)
		max=a[gn-i-1][gn-j-1];
	if(a[i][gn-j-1] >  max)
		max=a[i][gn-j-1];
	return max;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin>>q;
	while(q--){
		ll ans=0;
		int n;
		cin>>n;
		gn = n<<1;
		f(i,0,2*n)
		f(j,0,2*n)
		cin>>a[i][j];
		f(i,0,n)
			f(j,0,n){
				//cout<<i<<','<<j<<":"<<solve(i,j)<<endl;
				ans += solve(i,j);
		}
		cout<<ans<<endl;
	}
	return 0;
}