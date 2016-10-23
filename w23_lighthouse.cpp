#include <bits/stdc++.h>
#define f(i,a,b) for( int i = ( a ), __ = ( b ); i < __; ++i )
#define fr(i,b,a) for( int i = ( b ), __ = ( a ); i >= __; --i )
#define pb push_back
#define mp make_pair
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef map<int,int> mii;
typedef map<int,string> mis;
typedef map<string,int> msi;
typedef map<ll,ll> mll;
typedef map<ll,string> mls;
typedef map<string,ll> msl;
typedef set<int> si;
typedef set<string> ss;
typedef set<ll> sll;
typedef set<ld> sld;
typedef pair<int,int> ii;
vs s;
int n;

double d(int a1,int b1,int a2,int b2){
	double x1 = a1;
	double x2 = a2;
	double y1 = b1;
	double y2 = b2;
	return sqrt( (a1-a2)*(a1-a2) + (b1-b2)*(b1-b2) ) ;
}

bool test(int x,int y,int l){
	double eps = 0.00001;
	f(i,0,n){
		f(j,0,n){
			if( d(i,j,x,y) <= (double)l+eps)
				if(s[i][j] != '.')
					return false;
		}
	}
	return true;

}
void solve(){
	int ans = INT_MIN;
	ii point;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			for(int k=0;k<n;++k)
				if(s[i][j] == '.' && test(i,j,k)){
					if(k  > ans){
						point.x = i;
						point.y = j;
						ans = k;
					}
				}
				else break;
		}
	}
	cout<<ans<<endl;
	cout<<point.x<<' '<<point.y<<endl;
}

int main(){
	cin>>n;
	for(int i=0;i<n;++i){
		string temp;
		cin>>temp;
		s.pb(temp);
	}
	solve();
	return 0;
}
