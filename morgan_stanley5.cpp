#include <bits/stdc++.h>
using namespace std;

bool cmp(node *a,node *b){
	return a->id < b->id;
}

struct node{
	int id;
	set<node *,cmp> nbd;
};

node **G;
int n;	//graph size
void solve(){
	while(true){
		f(i,0,n){
			if(G[i]->nbd.size()==1){
				
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	return 0;
}