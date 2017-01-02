#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;
/* This function calculates (a^b)%MOD */
long long pow(int a, int b, int MOD){
    long long x=1,y=a;
    while(b > 0)    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}
long long InverseEuler(int n, int MOD)
{
    return pow(n,MOD-2,MOD);
}

long long C(int n, int r, int MOD)
{
    if(r>n)
        return 0;
    vector<long long> f(n + 1,1);
    for (int i=2; i<=n;i++)
        f[i]= (f[i-1]*i) % MOD;
    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}



int main() {
    int n;
    cin>>n;
    int h=(n+1)/2;
    int t=n/2;
    lli mod=(int)(1e9+7);
    lli answer=0;
    for(int i=1;i<n;i++){
        answer+= (((C(h,(i+1)/2,mod) *C(t,i/2,mod))%mod)+((C(t,(i+1)/2,mod) *C(h,i/2,mod))%mod))%mod;
    }
    cout<<(answer%mod)<<endl;
    return 0;
}

