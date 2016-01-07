#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MOD 1000000007
using namespace std;
typedef long long int lli;
lli pow(int n){
    if(n==0)
        return 1;
    lli a=pow(n/2);
    if(n&1)
        return (2*(a%MOD)*(a%MOD))%MOD;
    else return ((a%MOD)*(a%MOD))%MOD;
}

lli count_xor(lli *a,int size){
    int zero_and_one[2];
    zero_and_one[0]=0;
    zero_and_one[1]=0;
    for(int i=0;i<size;i++){
        //cout<<"Number"<<a[i]<<endl;
        zero_and_one[a[i]&1]++;
    }
    if(zero_and_one[1]==0)
        return 0;
    //cout<<"output:"<<pow(zero_and_one[0]+zero_and_one[1]-1)<<endl;
    return pow(zero_and_one[0]+zero_and_one[1]-1);
}

int main() {
    int test;
    cin>>test;
    lli *A;
    int n;
    for(int i=0;i<test;i++){
        cin>>n;
        A=new lli[n];
        int count=0;
        for(int j=0;j<n;j++){
            cin>>A[j];
            if(A[j]!=0)
                count++;
        }
        lli answer=0;
        int pow=1;
        while(count!=0){
            answer+=((pow%MOD)*(count_xor(A,n)%MOD))%MOD;
            pow*=2;
            pow%=MOD;
            count=0;
            for(int i=0;i<n;i++){
                A[i]=(A[i]>>1);
                if(A[i]!=0)
                    count++;
            }
        }
        cout<<answer%MOD<<endl;
    }
    return 0;
}
