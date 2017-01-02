#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;
ll gcd(ll a,ll b){
    if(b==0)
        return a;
    else return gcd(b,a%b);
}


int main() {
    int n;
    cin>>n;
    int r[(int)1e4+5];
    for(int i=0;i<n;++i)
        cin>>r[i];
    ll sig= (n*(n+1))/2;
    ll sum =0;
    for(int i=0;i<n;++i){
        sum+=(i+1)*r[i];
    }
    ll g=gcd(sig,sum);
    cout<<(sum/g)<<' '<<(sig/g)<<endl;
    cout<<1<<' '<<((n*(n+1))/2)<<endl;
    return 0;
}
