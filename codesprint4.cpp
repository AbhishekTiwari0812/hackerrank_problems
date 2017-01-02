<<<<<<< HEAD
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define f(i,a,b) for( int i = ( a ), __ =(b); i < __; ++i )
#define fr(i,a,b) for( int i = ( a ), __= (b) ; i >= __; --i )
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int>ii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef set<int> si;
typedef set<string> ss;
typedef set<ll> sl;
typedef set<ld> sd;
typedef map<string,int> msi;
typedef map<string,ll> msl;
typedef map<string,ld> msd;
typedef map<string,string> mss;
typedef map<int,string> mis;
typedef map<ll,string> mls;
typedef map<ld,string> mds;
string a,b;
int l1,l2;

int dp[1002][1002];

bool solve(int i,int j){
	if(j>=l2 && i <= l1)
		return true;
	else if( i == l1 && j < l2){
		return false;
	}
	else if( dp[i][j]!=-1)
		return dp[i][j];
	if(a[i] == b[j] || a[i]-'a'+'A' == b[j]){
		bool a = solve(i+1,j+1);
		bool b = solve(i+1,j);
		dp[i][j] = a|b;
		return a|b;
	}
	else if(a[i] != b[j] && a[i] >='A' && a[i] <= 'Z')
		return false;
	else{
		dp[i][j] = solve(i+1,j);
		return dp[i][j];
	}
}

void init(){
	for(int i=0;i<l1;++i){
		for(int j=0;j<l2;++j)
			dp[i][j]=-1;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin>>q;
	while(q--){
		cin>>a>>b;
		l1 = a.length();
		l2 = b.length();
		init();
		bool flag = solve(0,0);
		if(flag)
			cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
=======
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
#define f(i,x,y) for(long long i=x;i<y;i++)
#define fr(i,x,y) for(long long i=x;i>=y;i--)
long long my_graph[505][505],N=0,M=0,Source=0,Destination=0;
long long my_distance_2[505],dis2[505];

long long d_min(long long path_length[],bool edge_destroyer[]){
   long long min=1e10,min_index;
    f(second,0,N)
     if (edge_destroyer[second]==false && path_length[second]<=min)
         min = path_length[second],min_index=second;
 
   return min_index;
}
void find_path(int src,long long path_length[])
{
     bool edge_destroyer[505];
     f(i,0,505)
        path_length[i]=1e10,edge_destroyer[i]=false;
     path_length[src]=0;
     f(i,0,N){
           long long first=d_min(path_length,edge_destroyer);
           edge_destroyer[first]=true;
           f(second,0,N)
             if (!edge_destroyer[second] && my_graph[first][second] && path_length[first]!=1e10 && path_length[first]+my_graph[first][second]<path_length[second])
                path_length[second]=path_length[first]+my_graph[first][second];
         }
 
   
}
void find_shortest_path_greedy(){
    find_path(Source,my_distance_2);
    find_path(Destination,dis2);
    long long cost=my_distance_2[Destination];
    f(i,0,N)
        f(j,0,N)
            if(my_graph[i][j]+my_distance_2[i]+dis2[j]==cost)
                    my_graph[i][j]=0;my_graph[j][i]=0;
   
}
void get()
{
    find_shortest_path_greedy();
    find_shortest_path_greedy();
    find_shortest_path_greedy();
    if(my_distance_2[Destination]==1e10)cout<<-1<<endl;
    else
    cout<<my_distance_2[Destination]<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        f(i,0,505)
            f(j,0,505)
            my_graph[i][j]=0;
        t--;
        cin>>N>>M>>Source>>Destination;
        f(i,0,M)
        {
            int x,y,c;
            cin>>x>>y>>c;
            my_graph[x][y]=c;
            my_graph[y][x]=c;
        }
        get();
    }
>>>>>>> edcbdab16873cb7cba4478ee18f05d989cec02c9
}