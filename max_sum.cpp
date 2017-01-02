#include <iostream>
using namespace std;

long long Max(long long &a, long long &b){
    return a>b?a:b;
}

long long  maxSubArraySum(long long  *a, long long  size){
   long long  global_max = a[0];
   long long  Current = a[0];
   for (long long  i = 1; i < size; i++){
        Current = max(a[i], Current+a[i]);
        global_max = Max(global_max, Current);
   }
   return global_max;
}

int  main(){
  int test;
  cin>>test;
  while(test--){
    int n;
    cin>>n;
    long long  *a = new long long[n];
    for(int i=0;i<n;++i)
    cin>>a[i];
    long long  max_sum = maxSubArraySum(a, n);
    cout<<max_sum<<endl;
  }
  return 0;
}
