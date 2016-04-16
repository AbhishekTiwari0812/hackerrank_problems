#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int value;
    vector<node *>nbd;
    bool visited;
    int pre_time;
    node *parent;
    int post_time;
};

int size;
node **G;
int PRE_TIME,POST_TIME;
void dfs_visit(node *current){
    current->pre_time=PRE_TIME++;
    current->visited-true;
    for(int i=0;i<current->nbd.size();i++){
        if(!current->nbd[i]->visited){
            dfs_visit(current->nbd[i]);
        }
    }
    current->post_time=POST_TIME++;
}
void DFS(){
    for(int i=0;i<size;i++){
        if(G[i]->visited!=true){
            dfs_visit(G[i]);
        }
    }
}

int main() {
    PRE_TIME=0;
    POST_TIME=1;
    int n,T;
    cin>>n>>T;
    G=new node*[n];

    for(int i=0;i<n-1;i++){
        G[i]=new node;
        G[i]->value=i+1;
        G[i]->visited=false;
        G[i]->parent=NULL;
    }
    for(int i=0;i<n-1;i++){
        int a=0;
        int b=0;
        cin>>a>>b;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
