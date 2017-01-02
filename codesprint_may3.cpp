#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef vector<int> vi;
typedef vector<lli> vl;
typedef vector<string> vs;

int main(){
    int t;
    cin>>t;
    int n,k;

    while(t--){
      cin>>n>>k;
      if(k!=0){
        if( n % (2*k)==0){
          for(int i=0;i<n;i++){
            int t=i/k;
            if(t%2==0)
              cout<<(i+k+1)<<" ";
            else
              cout<<(i-k+1)<<" ";
          }
          cout<<endl;
        }
        else
          cout << (-1)<<endl;
    }
    else{
        for(int i=1;i<=n;i++)
            cout<<i<<" ";
        cout<<endl;
    }
  }
  return 0;

}

