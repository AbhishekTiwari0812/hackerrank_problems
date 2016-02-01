#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
typedef long long int lli;
typedef long double ld;
using namespace std;

int NEW_ID;
struct node;


struct node{
	bool visited;
	int id;
	int value;
	node *parent;
	int picked_value;
	int not_picked_value;
	vector<node *>nbd;
	node(int value,int id){
		this->value=value;
		this->visited=false;
		this->id=id;
		this->parent=NULL;
	}
};

map<int,node *>m;

void create_node(int value){
	NEW_ID++;
	node *temp=new node(value,NEW_ID);
	m[NEW_ID]=temp;
}

void create_edge(int id1,int id2){
	node *temp1=m[id1];
	node *temp2=m[id2];
	temp2->nbd.push_back(temp1);
	temp1->nbd.push_back(temp2);
	//this step maybe ommited if the changes are reflected in the map
	m[id1]=temp1;
	m[id2]=temp2;
}

void calculate_tree_value(node *root){
	int value1=0;
	int value2=0;
	root->visited=true;
	for(int i=0;i<root->nbd.size();i++){
		if(root->nbd[i]!=root->parent){
			root->nbd[i]->parent=root;
			calculate_tree_value(root->nbd[i]);
		}
	}
	//current node is picked
	for(int i=0;i<root->nbd.size();i++){
		if(root->nbd[i]!=root->parent){
			value1+=root->nbd[i]->not_picked_value;
		}
	}
	root->picked_value=value1+root->value;
	//current node is not picked
	for(int i=0;i<root->nbd.size();i++){
		if(root->nbd[i]!=root->parent){
			value2 += max(root->nbd[i]->picked_value,root->nbd[i]->not_picked_value);
		}
	}
	root->not_picked_value=value2;
	
}

void merge_and_create(int id){
	node *temp=m[id];
	calculate_tree_value(temp);
	create_node(max(temp->picked_value,temp->not_picked_value));
}

int main(){
	NEW_ID=0;
	int n;
	cin>>n;
	string s;
	int p,q;
	for(int i=0;i<n;i++){
		cin>>s;
		if(s=="A"){
			cin>>p;
			create_node(p);
		}
		else if(s=="B"){
			cin>>p>>q;
			create_edge(p,q);
		}
		else{
			cin>>p;
			merge_and_create(p);
		}
	}
	int answer=0;
	for(map<int,node *>::iterator it=m.begin();it!=m.end();it++){
		if(it->second->visited == false){
			calculate_tree_value(it->second);
			answer+=max(it->second->picked_value,it->second->not_picked_value);
		}
	}
	cout<<answer<<endl;


	return 0;
}