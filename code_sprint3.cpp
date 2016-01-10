#include <iostream>
#include <vector>
using namespace std;



class Node{
	public: 
		int value;
		Node *parent;
		vector <int> children_id;
		bool is_visited;
		int sub_tree_sum;
		
};

//have to make it global
Node *nodes_in_tree;

int calculate_sub_tree_sum(Node *root){
	if(root==NULL)
		return 0;
	int total_value=0;
	for(int i=0; i < root->children_id.size();i++)
		if(nodes_in_tree[root->children_id[i]].is_visited!=1)
			total_value+=calculate_sub_tree_sum(&nodes_in_tree[root->children_id[i]]);		//no subproblem repetition,so no worries here.
	root->is_visited=1;
	total_value+=root->value;
	root->sub_tree_sum=total_value;
	return total_value;
}
int SUM_TOTAL;
int find_optimal_choice(Node & Root){
	int till_root_total=Root.sub_tree_sum;
	int result=-1;
	for(int i=0;i<Root.children_id.size();i++){
		if(2*nodes_in_tree[Root.children_id[i]].sub_tree_sum > nodes_in_tree[0].sub_tree_sum )
			result = find_optimal_choice(nodes_in_tree[Root.children_id[i]]);
	}

	int max=0;
	for(int i=0;i<Root.children_id.size();i++)
		if(nodes_in_tree[Root.children_id[i]].sub_tree_sum > max)
			max=nodes_in_tree[Root.children_id[i]].sub_tree_sum;
	if(result==-1)
		return till_root_total;
	else return result-max;

}
int main(){
	int number_of_nodes;
	cin>>number_of_nodes;
	nodes_in_tree= new Node[number_of_nodes];
	int value;
	for(int i=0;i<number_of_nodes;i++){
		cin>>value;
		nodes_in_tree[i].value=value;
		nodes_in_tree[i].is_visited=false;
		nodes_in_tree[i].sub_tree_sum=-1;
	}
	int number_of_edges=number_of_nodes-1;
	//cin>>number_of_edges;
	int node1;
	int node2;
	for(int i=0;i<number_of_edges;i++){
		cin>>node1;
		cin>>node2;
		nodes_in_tree[node1-1].children_id.push_back(node2-1);
		nodes_in_tree[node2-1].parent = &nodes_in_tree[node1-1];
	}
	calculate_sub_tree_sum(&nodes_in_tree[0]);
	int optimal_value=find_optimal_choice(nodes_in_tree[0]);
	cout<<optimal_value<<endl;

}