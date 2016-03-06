#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


long long *cons(long long *A,long long left,long long right,long long flag){
    long long size=right-left+1;
    long long *temp=new long long[size];
    if(flag==1){
        temp[0]=A[left];
        for(long long i=1;i<size;i++){
            temp[i]=temp[i-1]+A[i+left];
        }
        return temp;
    }
    else{
        temp[0]=A[right];
        for(long long i=1;i<size;i++){
            temp[i]=temp[i-1]+A[right-i];
        }
        return temp;
    }
}
long long count(long long *A,long long left,long long right){
    if(left==right){
        if(A[left]>=0)
            return 1;
        else return 0;
    }
    else{
        long long mid;
        mid=(left+right)/2;
        long long a=count(A,left,mid);
        long long b=count(A,mid+1,right);
        long long *left_sub=cons(A,left,mid,-1);
        long long *right_sub=cons(A,mid+1,right,1);
        sort(left_sub,left_sub+(mid-left+1));
        sort(right_sub,right_sub+(right-mid));
        long long count=0;
        long long lsize=mid-left+1;
        long long rsize=right-mid;
        long long index=rsize-1;
        for(long long i=0;i<lsize;i++){
            if(index!=-1)
            while(right_sub[index] >= -1*left_sub[i]){
                index--;
                if(index<0)
                    break;
            }
            count+= (rsize-index-1);
        }
        return a+b+count;
    }
}

int main() {
    long long n;
    cin>>n;
    long long *A=new long long[n];
    for(long long i=0;i<n;i++){
        cin>>A[i];
    }
    long long temp;
    for(long long i=0;i<n;i++){
        cin>>temp;
        A[i]-=temp;
    }
    cout<<count(A,0,n-1)<<endl;
    return 0;
}
