#include <climits>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef long long int lli;
struct node{
	int id;
	int ready;
	lli value;
	int l,r;
	node *lp;		//to improve the algo
	node *rp;		//to improve the algo
	vector<node *> child;
};
node **G;
int n;
class compare{
public:
	bool operator()(const node *a,const node *b)const{
		return a->id < b->id;
	}
};
set<node *,compare> remain;
set<node *,compare>::iterator temp_it;

node *decide(){
	lli profit=INT_MAX;
	node *answer_node=NULL;
	int index;
	int remaining_size=remain.size();
	lli temp_profit;
	/*for(int i=0;i<n;i++){
		if(G[i]->ready==1){
			temp_it=remain.find(G[i]);
			index=distance(remain.begin(),temp_it);
			temp_profit=G[i]->value*(remaining_size-index);
			if(temp_profit < profit ){
				profit=temp_profit;
				answer_node=G[i];
			}
		}
	}*/
    for(int i=0;i<n;i++){
		if(G[i]->ready==1){
	        //temp_it=remain.find(G[i]);
			//index=distance(remain.begin(),temp_it);
			//temp_profit=G[i]->value*(remaining_size-index);
			//if(temp_profit < profit ){
				profit=temp_profit;
				answer_node=G[i];
			//}
		  if(G[i]->value < 0)
              return G[i];
        }
	}
    for(int i=n-1;i>=0;i--){
		if(G[i]->ready==1){
	        //temp_it=remain.find(G[i]);
			//index=distance(remain.begin(),temp_it);
			//temp_profit=G[i]->value*(remaining_size-index);
			//if(temp_profit < profit ){
				profit=temp_profit;
				answer_node=G[i];
			//}
           return G[i];
        }
	}
    
    
	return NULL;
}
void remove_dependency(node *current){
	for(int i=0;i<n;i++){
		if(G[i]->ready!=1){
			if(current->id < G[i]->id ){
				if(current->id >= G[i]->l)
					G[i]->ready+=1;
			}else{
				if(current->id <= G[i]->r)
					G[i]->ready+=1;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin>>n;
	G=new node *[n];
	lli value;
	for(int i=0;i<n;i++){
		G[i]=new node;
		G[i]->ready=1;
		G[i]->id=i;
		G[i]->l=INT_MIN;
		G[i]->r=INT_MAX;
		cin>>value;
		G[i]->value=value;
		remain.insert(G[i]);
	}
	int q;
	cin>>q;
	int a,b;
	for(int i=0;i<q;i++){
		cin>>a>>b;
		a-=1;
		b-=1;
		if(a < b){
			if(a > G[b]->l){
				G[b]->ready-=1;
				G[b]->l=a;
			}
		}
		else{
			if(a < G[b]->r){
				G[b]->r=a;
				G[b]->ready-=1;
			}
		}
		if(G[b]->ready < -1)
			G[b]->ready=-1;
	}
	lli score=0;
	bool poss=true;
	vector<node *> ans;
	for(int i=0;i<n;i++){
		node *current=decide();
		if(current==NULL){
			poss=false;
			break;
		}
		ans.push_back(current);
		remove_dependency(current);
        current->l=current->id;
        current->r=current->id;
        current->ready=-1;
		remain.erase(current);
	}
	if(poss){
		for(int i=0;i<n;i++){
			int index=ans[i]->id;
           // cout<<"picked at #"<<i<<" is:"<<(index+1)<<endl;
			for(int j=0;j<index;j++){
				score+=G[j]->value;
			}
			G[index]->value=0;
		}
		cout<<score<<endl;
	}
	else
		cout<<"Impossible"<<endl;
	return 0;
}
