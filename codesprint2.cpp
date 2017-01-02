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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int iter=5;
    int a[5],b[5];
    int ans=0;
    f(i,0,iter)
        cin>>a[i];
    f(i,0,iter)
        cin>>b[i];
    
    f(i,0,iter)
        ans+=min(abs(10-max(a[i],b[i])+min(a[i],b[i])),abs(a[i]-b[i]));
    cout<<ans<<endl;
    return 0;
}



