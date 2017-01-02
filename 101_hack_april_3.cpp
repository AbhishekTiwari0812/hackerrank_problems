#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <climits>
typedef long long int lli;
typedef long double ld;
using namespace std;

struct edge{
	int cost;
	int u;
	int v;
};
struct mset{
	int count;
	int id;
	mset *parent;
};
bool cmp(edge a,edge b){
	return a.cost < b.cost;
}
map<lli,lli> edge_count;

mset **sets;
mset *p(mset *a){
	if(a->id==a->parent->id)
		return a;
	else return p(a->parent);
}

void join(mset *a, mset *b,int cost){
	mset *tempa=p(a);
	mset *tempb=p(b);
	if(tempa->count > tempb-> count){
		tempb->parent=tempa;
	}
	else{
		tempa->parent=tempb;
	}
	if(edge_count.find(cost)==edge_count.end()){
        
		edge_count[cost]=(tempa->count)*(tempb->count);
    }
	else{
		edge_count[cost]+=tempa->count*tempb->count;
	}
  //  cout<<"cost="<<cost<<endl;
   // cout<<"value:"<<edge_count[cost]<<endl;
    int temp=tempa->count;
    tempa->count+=tempb->count;
	tempb->count+=temp;
}
int bin_search(int *A,int l,int r,int key){
    int mid=(l+r)/2;
    if(l>=mid){
        if(A[mid] > key)
            return mid-1;
        else return mid;
    }
    if(A[mid]==key){
        return mid;
    }
    else if(A[mid] < key){
        return bin_search(A,mid+1,r,key);
    }
    else 
        return bin_search(A,l,mid-1,key);
}
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	t=1;
	while(t--){
		int n,q;
		cin>>n>>q;
		sets=new mset*[n];
		for(int i=0;i<n;i++){
            sets[i]=new mset;
			sets[i]->parent=sets[i];
			sets[i]->count=1;
			sets[i]->id=i;
		}
		edge G[n-1];
		int a,b,c;
		for(int i=0;i<n-1;i++){
			cin>>a>>b>>c;
			a-=1;
			b-=1;
			G[i].u=a;
			G[i].v=b;
			G[i].cost=c;
		}
        sort(G,G+n,cmp);
        for(int i=0;i<n-1;i++){
			join(sets[G[i].u],sets[G[i].v],G[i].cost);
		}
		map<lli,lli>::iterator last=edge_count.begin();
		for(map<lli,lli>::iterator it=edge_count.begin();it!=edge_count.end();it++){
			if(it!=edge_count.begin())
				it->second=last->second+it->second;
			last=it;
         //   cout<<" cost"<<(it->first)<<" value:"<<(it->second)<<endl;
		}
        edge_count[0]=0;
        edge_count[1000000000]=0;
        int *A=new int[edge_count.size()+2];
        A[0]=0;
        int i=1;
        A[edge_count.size()+1]=1000000000l;
        for(map<lli,lli>::iterator it=edge_count.begin();it!=edge_count.end();it++)
            A[i++]=it->first;
        for(int i=0;i<q;i++){
			cin>>a>>b;
            a-=1;
            int l1=bin_search(A,0,edge_count.size()-1,b);
            int l2=bin_search(A,0,edge_count.size()-1,a);
            cout<<(edge_count[A[l1]]-edge_count[A[l2]])<<endl;
        }
	}
	return 0;
}
