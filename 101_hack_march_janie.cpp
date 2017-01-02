#include <set>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int id;
    vector<node *>nbd;
    vector<int> cost;
    vector<node *>nbd;
    vector<int> cost;
    int visited;
    node *parent;
};
node **G;
int n,k;
int root_id;

set<int>dest;

void convert(node *current,node *parent,int cost){
    current->visited=1;
    for(int i=0;i<current->nbd.size();i++)
        if(current->nbd[i]->visited!=1){
            node *temp=current->nbd[i];
            if(dest.find(temp->id)!=dest.end()){
                temp->nbd.push_back(parent);
                temp->cost.push_back(cost+current->cost[i]);
                parent->nbd.push_back(temp);
                parent->cost.push_back(cost+current->cost[i]);
                parent=temp;
            }
            convert(temp,parent,cost+current->cost[i]);
    }
}
vector<int> all_costs;
void calculate(){
    for(set<int>::iterator it=dest.begin();it!=dest.end();it++){
        int i=(*it);
        if(G[i]->nbd.size()==1){
            G[i]->visited=2;
            node *current=G[i]->nbd[0];
            long temp_cost=0;
            node *parent;
            node *child;
            while(current->nbd.size()==2){
                if(current->nbd[0]->visited==2){
                    parent=current->nbd[1];
                    child=current->nbd[0];
                    temp_cost+=current->cost[0];
                }
                else{
                    parent=current->nbd[0];
                    child=current->nbd[1];
                    temp_cost+=current->cost[1];
                }
                current->visited=2;
                current=parent;
            }
            all_costs.push_back(temp_cost);
        }

    }

}


void print_tree(node *current){
    if(current->visited==500)
        return;
    current->visited=500;
    if(dest.find(current->id)!=dest.end()){
        cout<<"node :"<<current->id<<endl;
        for(int j=0;j<current->nbd.size();j++)
            print_tree(current->nbd[j]);
    }
}
long long final_cost;
void add_all(node *current){
    if(current->visited==700)
        return;
    current->visited=700;
    for(int i=0;i<current->cost.size();i++)
        final_cost+=current->cost[i];
    for(int i=0;i<current->nbd.size();i++){
        add_all(current->nbd[i]);
    }
}
int main() {
    cin>>n;
    cin>>k;
    final_cost=0;
    G=new node*[n];
    for(int i=0;i<n;i++){
        G[i]=new node;
        G[i]->visited=false;
        G[i]->id=i;
    }
    for(int i=0;i<k;i++){
        cin>>root_id;
        root_id--;
        dest.insert(root_id);
    }
    int a,b,c;

    for(int i=0;i<n-1;i++){
        cin>>a>>b>>c;
        a-=1;
        b-=1;
        G[a]->nbd.push_back(G[b]);
        G[a]->cost.push_back(c);
        G[b]->nbd.push_back(G[a]);
        G[b]->cost.push_back(c);
    }

    //convert(G[root_id],G[root_id],0);
    calculate();
    sort(all_costs.begin(),all_costs.end());
    final_cost-=all_costs[all_costs.size()-1];
    final_cost-=all_costs[all_costs.size()-2];
    cout<<final_cost<<endl;
    return 0;
}
