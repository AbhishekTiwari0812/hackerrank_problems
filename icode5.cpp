#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct edge{
	long id;
	ll cost;
};

struct node{
	vector<edge> nbd;
	long id;
	long reach_cost;
};
class cmp{
public:
	bool operator()(const node &a, const node &b)const{
		return a.reach_cost < b.reach_cost;
	}
};

node *g;
long n;
long x,y;

long dijkstra(long s, long d){
	long *visited=new long[n];
	for(long i=0;i < n;++i)
		visited[i] = 0;
	
	for(long i=0;i<n;++i){
		if(i != s)
			g[i].reach_cost = LONG_MAX;
		else 
			g[i].reach_cost = 0;
	}
	priority_queue<node, vector<node >, cmp > q;
	q.push(g[s]);
	while(!q.empty()){
		node temp = q.top();
		q.pop();
		if(visited[temp.id] == 6){
			continue;
		}
		visited[temp.id]++;
		for(long i=0; i < temp.nbd.size(); ++i){
			if(visited[temp.nbd[i].id] < 6){
				if( temp.reach_cost + temp.nbd[i].cost  < g[temp.nbd[i].id].reach_cost){
					g[temp.nbd[i].id].reach_cost = temp.reach_cost + temp.nbd[i].cost;
					q.push(g[temp.nbd[i].id]);
				}
			}
		}
	}
	return g[d].reach_cost;
}

vector<edge> add(long index1, long c_val){
	vector<edge> temp_help;
	for(long i=0; i < g[index1].nbd.size(); ++i){
		edge e1,e2,e3;
		long index2 = g[index1].nbd[i].id;
		long edge_cost = g[index1].nbd[i].cost;
		e1.id = index2;
		e1.cost = ( edge_cost ^ x )+ c_val;
		temp_help.push_back(e1);
		e2.id = index2; e2.cost = (edge_cost ^ y) + c_val;
		temp_help.push_back(e2);
		e3.id = index2;
		e3.cost = (edge_cost ^ y ^ x) + c_val;
		temp_help.push_back(e3);
	}
	return temp_help;
}


int main(){
	cin>>n;
	g = new node[n];
	for(long i=0;i < n;++i){
		g[i].id = i;
	}
	long m;
	cin>>m;
	long s,t;
	ll x,y;
	cin>>s>>t>>x>>y;
	long temp1,temp2,c;
	for(long i=0;i < m;++i){
		cin>>temp1>>temp2>>c;
		temp1--;
		temp2--;
		edge e;
		e.id = temp2;
		e.cost = c;
		g[temp1].nbd.push_back(e);
		e.id = temp1;
		e.cost = c;
		g[temp2].nbd.push_back(e);
	}
	long cost_list[n];
	for(long i=0;i<n;++i){
		cin>>cost_list[i];
	}
	for(long i=0;i < n;++i){
		vector<edge> temp_help = add(i,cost_list[i]);
		for(long j = 0;j < temp_help.size();++j){
			g[i].nbd.push_back(temp_help[j]);
		}
	}
	cout<<dijkstra(s-1,t-1)<<endl;
	return 0;
}
