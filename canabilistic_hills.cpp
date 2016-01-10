#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

typedef struct edge{
	int u;
	int id;
	int v;
	int is_visited;
}edge;

int VISIT_NUM;
edge **G;
int *START;
int num_of_nodes;
int size;
void print_all();

int dfs_visit(int current,int flag){
//	cout<<"current"<<current<<endl;
//	print_all();
	if(current==num_of_nodes)
		flag=1;
	if(current==1 && flag==1)
		return 1;	
	int start=START[current-1]; 
	int end;
	if(current==num_of_nodes)
		end=size-1;
	else end=START[current]-1;   
	int path_found_indicator=-1;
	for(int i=start;i<=end;i++){
		if(G[i]->is_visited!=VISIT_NUM){
			G[i]->is_visited=VISIT_NUM;
			path_found_indicator = dfs_visit(G[i]->v ,flag);
			if(path_found_indicator==1)
				return 1;
		}
	}
	VISIT_NUM++;
	return 0;
}

int DFS(){
	int path_found_indicator=-1;
	for(int i=0;i<size;i++){
		if(G[i]->u != 1){
			VISIT_NUM++;
			return 0;
		}
		if(G[i]->is_visited!=VISIT_NUM){
			VISIT_NUM++;
			path_found_indicator = dfs_visit(G[i]->u,0);
			if(path_found_indicator==1)
				return 1;
		}

	}
	VISIT_NUM++;
	return 0;

}


void print_all(){
	for(int i=0;i<size;i++){
		cout<<"("<<G[i]->u<<","<<G[i]->v<<") is_visited="<<G[i]->is_visited<<endl;
	}
}

void assign_indices(){
	int old=-1;
	for(int i=0;i<size;i++)
		if(old!=G[i]->u-1){
			old=G[i]->u-1;
			START[old]=i;
		}
}


bool comp(edge *a,edge *b){
	return a->u < b->u;
}

int main(){
	int test;
	cin>>test;
	int u,v;
	for(int i=0;i<test;i++){
		VISIT_NUM=0;
		cin>>num_of_nodes>>size;
		START=new int[num_of_nodes];
		G=new edge*[size];
		for(int j=0;j<size;j++){
			G[j]=new edge;
			cin>>u>>v;
			G[j]->u=u;
			G[j]->v=v;
			G[j]->is_visited=-1;
			G[j]->id=j;
		}
		if(size!=0)
			sort(G,G+size,comp);
		assign_indices();
		int something=DFS();
		if(something==1)
			cout<<"Go on get the Magical Lamp"<<endl;
		else cout<<"Danger!! Lucifer will trap you"<<endl;
		
	}


	
}