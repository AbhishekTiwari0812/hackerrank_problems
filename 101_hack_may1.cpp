#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

typedef unsigned int lli;
struct node{
    lli value;
    lli i;
    lli j;
};
bool cmp(node a,node b){
    return a.value < b.value;
}


int main() {
    lli n;
    cin>>n;
    lli *A=new lli[n];
    lli n1=(n*(n-1))/2;
    node *B=new node[n1];
    for(lli i=0;i<n;i++){
        cin>>A[i];
    }
    lli k=0;
    for(lli i=0;i<n;i++)
        for(lli j=i+1;j<n;j++){
            B[k].i=i;
            B[k].j=j;
            B[k++].value=A[i]^A[j];
    }
    sort(B,B+n1,cmp);
    lli *some_new_name=new lli[n];
    for(lli i=0;i<n;i++)
        some_new_name[i]=n-1;
    lli flag=0;
    for(lli i=0;i<n1;i++){
        if(some_new_name[B[i].i] == 2){
            flag++;
        }
        else if(some_new_name[B[i].i] == 1 || some_new_name[B[i].j] == 1){
            cout<<(B[i].value)<<endl;
            return 0;
        }

        if(some_new_name[B[i].j] == 2){
            flag++;
        }
        if(flag > 2){
            cout<<(B[i].value)<<endl;
            return 0;
        }
        some_new_name[B[i].i]-=1;
        some_new_name[B[i].j]-=1;

    }
    return 0;
}
