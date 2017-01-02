#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long int ll;
ll fact(ll n){
    if(n!=0)
        return n*fact(n-1);
    else return 1;
}

int main() {
    ll n,m,c;
    cin>>n>>m>>c;
    ll sum = n+m-c;
    sum-=1;
    cout<<fact(sum)<<endl;
    return 0;
}
