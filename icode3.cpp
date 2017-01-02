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
string a,b;

void solve(){
	int j = 0;
	f(i,0,b.length()){
		if(a[j] != b[i]){
			cout<<"NO\n";
			return;
		}
		if( i+1 < b.length() && b[i+1] == b[i]){
			j++;
			continue;
		}
		else{
			while( j < a.length()){
				if(a[j+1]==a[j]){
					j++;
				}
				else{
					j++;
					break;
				}
			}
		}

	}
	cout<<"YES\n";
}
int main(){
	int n;
	cin>>n;
	f(i,0,n){
		cin>>a>>b;
        a += "$$$";
        b += "$";
		if(b.length() > a.length() ){
			cout<<"NO\n";
			continue;
		}
		else{
			solve();
		}
	}
	return 0;
}