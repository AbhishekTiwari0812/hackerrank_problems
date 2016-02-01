#include <set>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
typedef long long int lli;
using namespace std;


struct node{
    int value;
    vector<node *> nbd;
    int visited;
    node *parent;
};

struct point{
    int x;
    int y;
    point(int a,int b){
        x=a;
        y=b;
    }
};

node **G;
int n;
int iter_num;
class comp{
public:
    bool operator()(const point &a,const point &b)const{
        if(a.x==b.x){
            return a.y<b.y;
        }
        else return a.x<b.x;
    }
};

set<point,comp> s;



int is_valid(node *a,node *b){
    if(s.find(point(a->value,b->value))!=s.end())
        return 1;
    else
    iter_num++;
    lli needed= (b->value*(b->value+1))/2 -(a->value*(a->value-1))/2;
    queue<node *> q;
    a->visited=iter_num;
    q.push(a);
    while(!q.empty()){
        node *temp=q.front();
        q.pop();
        needed-=temp->value;
        if(needed==0)
            return 1;
        else{
            int size=temp->nbd.size();
            for(int i=0;i<size;i++){
                if(temp->nbd[i]->value <= b->value && temp->nbd[i]->value >= a->value)
                if(temp->nbd[i]->visited!=iter_num){
                    temp->nbd[i]->visited=iter_num;
                    q.push(temp->nbd[i]);
                }
            }
        }

    }
    if(needed==0)
        return 1;
    return 0;
}

void generate_more(){
    point temp(-1,-1);
    for(set<point,comp>::iterator it=s.begin();it!=s.end();it++){
        temp=(*it);
        if(temp.x!=temp.y){
            set<point,comp>::iterator it2;
            it2=s.find(point(temp.y,temp.y));
            it2++;
            while(it2->x==temp.y && it2!=s.end()){
                s.insert(point(temp.x,it2->y));
                it2++;
            }
        }
    }
}
int code2();
int code1();

int main(){
    iter_num=0;
    n=0;
    scanf("%d",&n);
    if(n>300)
        code1();
    else code2();
}

int code1() {
    
    G=new node*[n];
    for(int i=0;i<n;i++){
        G[i]=new node;
        G[i]->parent=NULL;
        G[i]->value=i+1;
        G[i]->visited=0;
    }
    int a,b;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        a-=1;
        b-=1;
        G[a]->nbd.push_back(G[b]);
        G[b]->nbd.push_back(G[a]);
        s.insert(point(G[i]->value,G[i]->value));
    }
    int count=0;
    int j;
    for(int i=0;i<n-1;i++){
        j=i+1;  
        int t=is_valid(G[i],G[j]);
        if(t==1)
            s.insert(point(G[i]->value,G[j]->value));
    }
    generate_more();
    generate_more();
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++){
            count+=is_valid(G[i],G[j]);
        }
    printf("%d\n",(count+n));
    return 0;
}


int is_valid2(node *a,node *b){
    iter_num++;
    lli needed= (b->value*(b->value+1))/2 -(a->value*(a->value-1))/2;
    queue<node *> q;
    a->visited=iter_num;
    q.push(a);
    while(!q.empty()){
        node *temp=q.front();
        q.pop();
        needed-=temp->value;
        if(needed==0)
            return 1;
        else{
            for(int i=0;i<temp->nbd.size();i++){
                if(temp->nbd[i]->value <= b->value && temp->nbd[i]->value >= a->value)
                if(temp->nbd[i]->visited!=iter_num){
                    temp->nbd[i]->visited=iter_num;
                    q.push(temp->nbd[i]);
                }
            }
        }

    }
    if(needed==0)
        return 1;
    return 0;
}
int code2() {
    G=new node*[n];
    for(int i=0;i<n;i++){
        G[i]=new node;
        G[i]->parent=NULL;
        G[i]->value=i+1;
        G[i]->visited=0;
    }
    int a,b;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        a-=1;
        b-=1;
        G[a]->nbd.push_back(G[b]);
        G[b]->nbd.push_back(G[a]);
    }
    int count=0;

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){         
    //      cout<<i<<" "<<j<<is_valid2(G[i],G[j])<<endl;
            count+=is_valid2(G[i],G[j]);
        }
    }
    cout<<(count+n)<<endl;
    return 0;
}
