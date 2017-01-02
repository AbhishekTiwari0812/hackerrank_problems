<<<<<<< HEAD
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define f(i,a,x) for( int i = ( a ); i < (x); ++i )
#define fr(i,a,x) for( int i = ( a ); i >= ( x ); --i )
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
    int n;
    int k;
    int ans=0;
    int temp;
    int x,val;
    cin>>n;
    cin>>k;
    for(int i=0;i<n;i++){
        cin>>temp;
        if(i!=k)
            ans+=temp;
    }
    cin>>x;
    val=x-(ans/2);
    if(val)
        cout<<val<<endl; 
    else
        cout<<"Bon Appetit"<<endl;
    return 0;
}
=======
#include <iostream>

using namespace std;


int main(){
    int n;
    cin >> n;
    int temp;
    int num=0;
    for(int a_i = 0;a_i < n;a_i++){
       cin >> temp;
        num+=temp;
    }
    if(num&1)
        cout<<"No ";
    else cout<<"Yes ";
    cout<<num<<endl;
    return 0;
}
>>>>>>> edcbdab16873cb7cba4478ee18f05d989cec02c9
