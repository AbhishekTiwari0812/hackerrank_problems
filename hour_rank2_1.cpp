#include <iostream>
#include <algorithm>
#define MOD 1000000009
using namespace std;


typedef long long int lli;

lli pow(int a){
    if(a==1)
        return 2;
    else if(a==0)
        return 1;
    lli p;
    if(a&1){    
        p=pow(a/2);
        return (2*p*p)%MOD;
    }
    else {
        p=pow(a/2);
        return (p*p)%MOD;
    }
}

lli T(int n){
    if(n==3)
        return 1;
    return (2*T(n-1)%MOD+pow(n-2)%MOD-1)%MOD;
}

int main(){
    int N;
    cin >> N;
    int m;
    m=(N-1);
    cout<<T(N)<<endl;
    return 0;
}
