#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;
typedef vector<vector<vector<int> > > three_d;
lli *cost;
lli min_cost(int l,int r,int time,three_d &DP){
    if(l==r)
        return time*cost[l];
    lli a,b;
    if(l+1!=r){
        if(DP[l+1][r][time+1]!=-1)
            a=DP[l+1][r][time+1]+cost[l]*time;
        else {
            a=min_cost(l+1,r,time+1,DP)+cost[l]*time;
            DP[l+1][r][time+1]=a-cost[l]*time;
        }
    }
    else
        a=min_cost(l+1,r,time+1,DP)+cost[l]*time;
    if(l+1!=r){
        if(DP[l][r-1][time+1]!=-1)
            b=DP[l][r-1][time+1]+cost[r]*time;
        else {
            b=min_cost(l,r-1,time+1,DP)+cost[r]*time;
            DP[l][r-1][time+1]=b-cost[r]*time;
        }
    }
    else
        b=min_cost(l,r-1,time+1,DP)+cost[r]*time;
    return a<b?a:b;
}
int main() {
    int n;
    cin>>n;
    three_d DP(n, vector<vector<int> >(n,vector<int>(n,-1)));
    cost=new lli[n];
    for(int i=0;i<n;i++)
        cin>>cost[i];
    cout<<min_cost(0,n-1,1,DP)<<endl;
    return 0;
}
