#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    ll a[(ll)1e5+5];
    ll b[(ll)1e5+5];
    cin>>n;
    for(ll i=0;i<n;++i)
        cin>>a[i];
    for(ll i=0;i<n;++i)
        cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    ll remain=0;
    ll ops=0;
    for(ll i=0;i<n;++i){
        ops += abs(a[i]-b[i]);
        remain += a[i]-b[i];
    }
    if(remain!=0){
        cout<<(-1)<<endl;
    }
    else cout<<(ops/2)<<endl;
    return 0;
}
