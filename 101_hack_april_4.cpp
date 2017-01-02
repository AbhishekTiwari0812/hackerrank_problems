#include<map>
#include<string>
#include<iostream>
#include <sstream>
#include <cstdio>
#include<set>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fr(i,a,b) for(ll i=a;i>=b;i--)
#define ff(i,a,b,c) for(int i=a;i<b;i+=c)

#define vi vector<int>
#define vll vector<long long int>
typedef pair<pair<int,int> ,int> PII;
typedef pair<long long int,long long int> PI;
typedef pair<long long int, pair<int,int> > Pli;
typedef pair<int,string> PS;
typedef long long int ll;

ll mod_pow(ll a,ll n,ll b){ll res = 1;while(n){if(n&1) {res = (res*a)%b;}a = (a*a)%b;n >>= 1;}return res%b;}
ll mod_div(ll a,ll b,ll md){ll ans = (a*mod_pow(b,md-2,md))%md; return ans;}
ll mul(ll a,ll b,ll md){ return (ll)(a*b)%md;}
ll gcd(ll n,ll m){if(m<=n && n%m==0)return m;if(n<m)return gcd(m,n);else return gcd(m,n%m);}
ll add(ll a,ll b,ll md){a=((a%md)+(b%md))%md;return a;}
ll sub(ll a,ll b,ll md){return add(a,md-b,md);}
ll bC(int n,int r){ll ans=1;if(r>n-r)r=n-r;f(i,1,r+1)ans=(ans*(n-i+1))/(i);return ans;}
ll mod=1e9+7,ans=0;
ll dp[100005][26];
map<string,int> mp;
void init(ll n){
    f(i,0,n+2)
        f(j,0,26)dp[i][j]=0;
}
void solve(string s,ll n){

}
int main(){
    int t;
    cin>>t;
    while(t){
        t--;
        string s;
        cin>>s;
        init(s.length());
        f(i,0,s.length())
        {
            if(i==0){dp[i+1][s[i]-97]++;continue;}
            f(j,0,26)dp[i+1][j]=dp[i][j];
            dp[i+1][s[i]-97]++;
        }
        int n=s.length();
         f(i,0,n){
        f(j,i,n){
                string temp=s.substr(i,j-i+1);
                if(mp[temp]>0)continue;
                mp[temp]=1;
                int dis=0;
                f(k,0,26)
                {
                    if(dp[j+1][k]-dp[i][k]>0)dis++;
                }
                ans=add(ans,mod_pow(j-i+1,dis,mod),mod);
            }
    }
    cout<<ans<<endl;
    ans=0;
    mp.clear();
    }
}
