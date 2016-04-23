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
}