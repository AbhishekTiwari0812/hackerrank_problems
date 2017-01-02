#include <bits/stdc++.h>
#define f(i,a,b) for( int i = ( a ), __ = ( b ); i < __; ++i )
#define fr(i,b,a) for( int i = ( b ), __ = ( a ); i >= __; --i )
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

ifstream in;
ofstream out;


int main(){
	FastIO
	int n,m;
	ll a[(int)1e5+5];
	ll x[(int)1e5+5];
	cin>>n;
	f(i,0,n)
		cin>>a[i];
	cin>>m;
	f(i,0,m)
		cin>>x[i];
	sort(x,x+m);
	int laser=0;
	f(i,0,n){
		if(laser==m)
			break;
		if(x[laser] <= i+1){
			i--;
			laser++;
		}
		else{
			if(x[laser] - (i+1) < a[i]) 
				a[i] = x[laser]-(i+1);
			//cout<<"a["<<(i+1)<<"]:"<<a[i]<<endl;
		}
	}
	ll sum = 0;
	f(i,0,n)
		sum+=a[i];
	cout<<sum<<endl;
	return 0;
}

