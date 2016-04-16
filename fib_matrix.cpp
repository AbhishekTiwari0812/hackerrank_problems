#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MOD (int)(1e9+7)
using namespace std;
typedef long long lli;

lli **mul(lli **A,lli **B){
    lli **answer=new lli*[2];
    answer[0]=new lli[2];
    answer[1]=new lli[2];
    answer[0][0]=(((A[0][0]*B[0][0])%MOD)+((A[0][1]*B[1][0])%MOD))%MOD;
    answer[0][1]=(((A[0][0]*B[0][1])%MOD)+((A[0][1]*B[1][1])%MOD))%MOD;
    answer[1][0]=(((A[1][0]*B[0][0])%MOD)+((A[1][1]*B[1][0])%MOD))%MOD;
    answer[1][1]=(((A[1][0]*B[0][1])%MOD)+((A[1][1]*B[1][1])%MOD))%MOD;
    return answer;
}
lli **pow(lli **A,int n){
    lli **answer;
    if(n==1){
        
        return A;
    }
    if(n==0){
        A=new lli*[2];
        A[0]=new lli[2];
        A[1]=new lli[2];
        A[0][0]=1;
        A[1][0]=0;
        A[0][1]=0;
        A[1][1]=1;
        return A;
    }
    else{
        answer=pow(A,n/2);
        if(n&1)
            return mul(mul(answer,answer),A);
        else return mul(answer,answer);
    }
}
//fib[0]=1;
//fib[1]=1;
//fib[2]=2;
lli fib(int n){
    if(n==0)
        return 1;
    if(n==1)
        return 1;
    else{
        lli **A;
        A=new lli*[2];
        A[0]=new lli[2];
        A[1]=new lli[2];
        A[0][0]=1;
        A[1][0]=1;
        A[0][1]=1;
        A[1][1]=0;
        A=pow(A,n);
        return A[0][0];        
    }
    
}

lli f(lli a){
    
}
lli g(lli a){
    
}
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a;
    char c;
    while(n--){
        cin>>a>>c;
        if(c=='f'){
            cout<<f(a)<<endl;
        }
        else{
            cout<<g(a)<<endl;
        }
    }
    return 0;
}
