#include <iostream>
#include <vector>
using namespace std;
struct node{
	bool visited;
	std::vector<node *> nbd;
};
node **G;
int dfs_visit(node *current){
	int count=1;
	current->visited=true;
	for(int i=0;i<current->nbd.size();i++){
		if(current->nbd[i]->visited!=true)
			count+=dfs_visit(current->nbd[i]);
	}
	return count;
}
long long int DFS(int size){
	int comp_size;
	long long int total1=0;
	long long int total2=0;
	for(int i=0;i<size;i++){
		comp_size=0;
		if(G[i]->visited!=true){
			comp_size=dfs_visit(G[i]);
			total1+=comp_size;
			total2=total2+comp_size*comp_size;
		}
	}
	return (total1*total1-total2)/2;
}

int main(){

	int size;
	cin>>size;
	G=new node*[size];
	for(int i=0;i<size;i++){
		G[i]=new node;
		G[i]->visited=false;
	}
	int edges;
	cin>>edges;
	int a,b;
	for(int i=0;i<edges;i++){
		cin>>a>>b;
		G[a]->nbd.push_back(G[b]);
		G[b]->nbd.push_back(G[a]);
	}
	cout<<DFS(size)<<endl;
	return 0;
}