#include <iostream>
#include <vector>
using namespace std;

typedef struct node{
	bool is_visited;
	int value;
	vector<struct node *>neighbours;
	int pos[26];
}node;
node **G;
int nodes;
int GLOBAL_POS[26];
int ALL_ONE;


void query(char a,char b){
	if(ALL_ONE){
		cout<<"YES"<<endl;
		return ;
	}
	else if(GLOBAL_POS[b-a]){
		cout<<"YES"<<endl;
		return;
	}
	cout<<"NO"<<endl;
	return ;
}

void dfs_visit(node *current){
	if(ALL_ONE)
		return;
	for(int i=0;i<current->neighbours.size();i++){
		if(current->neighbours[i]->is_visited==false){
			current->neighbours[i]->is_visited=true;
			dfs_visit(current->neighbours[i]);
		}
	}
    
	current->pos[current->value%26]=1;
	
        for(int i=0;i<current->neighbours.size();i++)
            for(int j=0;j<26;j++)
                if(current->neighbours[i]->pos[j]==1){
                    current->pos[j]=1;
                    current->pos[(current->value+j)%26]=1;
                }
    if(current->neighbours.size()!=0){
        for(int j=0;j<26;j++)
            if(current->pos[j]==1)
                GLOBAL_POS[j]=1;
    }
    else GLOBAL_POS[current->value%26]=1;
	int flag=-1;
	for(int j=0;j<26;j++)
		if(GLOBAL_POS[j]!=1){
			flag=1;
			break;
		}
	if(flag==-1)
		ALL_ONE=1;
}

void DFS(){
	for(int i=0;i<nodes;i++)
		if(G[i]->is_visited==false){
			G[i]->is_visited=true;
			dfs_visit(G[i]);
		}
}
void print_pos(){
	for(int i=0;i<26;i++)
		if(GLOBAL_POS[i]==1)
			cout<<i<<" is possible\n";
}


int main(){
	int test;
	int num_of_queries;
	int edges;
	cin>>test;
	G=new node*[10000009];
	for(int i=0;i<test;i++){
		cin>>nodes;
		for(int i=0;i<26;i++)
			GLOBAL_POS[i]=0;
		ALL_ONE=0;
		edges=nodes-1;
		cin>>num_of_queries;
		int values;
		
		for(int i=0;i<nodes;i++){
			cin>>values;
			G[i]=new node;
		
			G[i]->is_visited=false;
			G[i]->value=values;
		}
		int A,B;
		for(int i=0;i<edges;i++){
			cin>>A>>B;
			A-=1;
			B-=1;
			G[A]->neighbours.push_back(G[B]);
		}
		DFS();
		print_pos();
		char a;
		char b;
		for(int i=0;i<num_of_queries;i++){
			cin>>a>>b;
			query(a,b);
		}
	
	}
	return 0;
}