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
int n;
ll a[(int)1e5+2];
ll m;
ll *help;
int size;
int bin_search(int l, int r,int k){
	if(l < r - 1 ){
		int mid = (l+r)/2;
		if(help[mid]==k)
			return mid;
		else if(help[mid] >  k)
			return bin_search(l,mid,k);
		else
			return bin_search(mid,r,k);
	}
	else{
		if(help[r] <= k)
			return r;
		else if(help[l] <= k)
			return l;
		else return l-1;
	}
}

ll daq(int l,int r){
	if(r < l)
		return LONG_MIN;
	if(l==r)
		return a[l];
	int mid = (l+r)/2;
	ll al = daq(l,mid);
	ll ar = daq(mid+1,r);
	size = r - mid;
	help = new ll[size];
	f(i,0,size)
		help[i] = a[i+mid+1];
	f(i,1,size)
		help[i] = ( help[i-1] + help[i] ) % m;
	sort(help,help+size);
	ll max = LONG_MIN;
	f(i,l,mid+1){
		int index = bin_search(0,size-1,m-a[i]-1);
		if(index < 0 || index >= size){
			continue;
		}
		else{
			if((help[index]+a[i])%m > max )
				max = (help[index]+a[i])%m;
		}
	}
	f(i,l,mid+1){
		int index = bin_search(0,size-1,m-1);
		if(index < 0 || index >= size){
			continue;
		}
		else{
			if((help[index]+a[i])%m > max )
				max = (help[index]+a[i])%m;
		}
	}
	if(max < ar)
		max = ar;
	if(max < al)
		max = al;
	return max;
}
void solve(){
	cout<<daq(0,n-1)<<endl;
}

int main(){
	//FastIO
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		f(i,0,n){
			cin>>a[i];
			a[i] %= m;
		}
		solve();
	}
	return 0;
}
