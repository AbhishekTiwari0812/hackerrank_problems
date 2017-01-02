#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    long long id;
    vector<node *>nbd;
    vector<bool> connector;
    vector<long long> cost;
    bool visited;
    bool dan;
};
node **G;
vector<long long> cost_list;

long long n,k;
bool DFS(node *current){
    bool answer=false;
    node *temp;
    bool temp_answer;
    for(long long i=0;i<current->nbd.size();i++){
        temp=current->nbd[i];
        if(!temp->visited){
            temp->visited=true;
            temp_answer=DFS(temp);
            if(temp_answer)
                cost_list.push_back(current->cost[i]);
            answer|=temp_answer;
        }
        current->connector.push_back(false);
    }
    //cout<<"here";
    return answer|current->dan;

}
void p(vector<long long> v){
    for(long long i=0;i<v.size();i++)
        cout<<v[i]<< " ";
    cout<<endl;
}
void p(vector<bool> v){
    for(long long i=0;i<v.size();i++)
        cout<<v[i]<< " ";
    cout<<endl;
}
void pn(vector<node *> v){
    for(long long i=0;i<v.size();i++)
        cout<<(v[i]->id)<< " ";
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    G=new node*[n];
    for(long long i=0;i<n;i++){
        G[i]=new node;
        G[i]->id=i;
        G[i]->visited=false;
        G[i]->dan=false;
    }
    long long a,b,c;
    for(long long i=0;i<n-1;i++){
        cin>>a>>b>>c;
        G[a]->nbd.push_back(G[b]);
        G[b]->nbd.push_back(G[a]);
        G[a]->cost.push_back(c);
        G[b]->cost.push_back(c);
    }
    for(long long i=0;i<k;i++){
        cin>>a;
        G[a]->dan=true;
    }
    G[0]->visited=true;
    DFS(G[0]);
  /*  for(long long i=0;i<n;i++){
        for(long long j=0;j<G[i]->nbd.size();j++){
            if(G[i]->connector[j])
                cost_list.push_back(G[i]->cost[j]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<"for "<<(G[i]->id)<<endl;
        pn(G[i]->nbd);
        p(G[i]->connector);
        p(G[i]->cost);
    }
*/
    long final_answer=0;
    sort(cost_list.begin(),cost_list.end());
   // p(cost_list);
    for(long long i=0;i<k-1;i++){
        final_answer+=cost_list[i];
    }
    cout<<final_answer<<endl;
    return 0;
}
