#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<ii > vii;

void solve(ll n){
    ll act_n=n;
    ll i=2;
    ll sum1=1;
    ll sum2=1;
    ll ans;
    while(i*i <= act_n){
        ans=0;
        while(n%i==0){
            n/=i;
            ans++;
        }
        sum1 *= ans+1;
        sum2 *= 2*ans+1;
        i++;

    }
    if(n!=1){
        sum1 *=2;
        sum2 *=3;
    }
    cout<<((sum2/2)-sum1+1)<<endl;
}

int main() {
    ll n;
    cin>>n;
    solve(n);
    return 0;
}
