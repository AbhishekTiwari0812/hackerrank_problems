#include <iostream>
using namespace std;
typedef long long lli;
lli MOD;
lli f[(lli)1e6];
void calculate_fibonacci(){
	f[0]=1;
	f[1]=1;
	for(lli i=2;i<(lli)1e6;i++){
		f[i]=(f[i-1]+f[i-2])%MOD;
	}
}

struct node{
	lli original;
	lli l;
	lli r;
	node *l_child;
	node *r_child;
	node *parent;
};
node *createSegTree(lli *A,lli left,lli right){
	if(right<left)
		return NULL;
	node *root=new node;
	root->parent=NULL;
	root->l=left;
	root->r=right;
	lli mid=(left+right)/2;
	root->l_child=createSegTree(A,left,mid);
	root->r_child=createSegTree(A,mid+1,right);
	if(root->l_child!=NULL)
		root->l_child->parent=root;
	if(root->r_child!=NULL)
		root->r_child->parent=root;
	root->original=0;
	//need only half not full
	// watch out for leaf nodes while modifying
	for(lli i=left;i<=right;i++){
		root->original+=(A[i]*f[i-left])%MOD;
		root->original%=MOD;
	}
	return root;
}

lli get_value(node *root,int left,int right){
	int mid=(left+right)/2;
	if(root->l==left && root->r==right)
		return (root->original)%MOD;
	else if(right<=mid){
		return get_value(root->l_child,left,right);
	}
	else if(left>mid){
		return get_value(root->r_child,left,right);
	}
	else {
		
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	lli n,m;
	cin>>n>>m>>MOD;
	
	lli a,b,c;
	lli *A=new lli[n];
	for(lli i=0;i<n;i++)
		cin>>A[i];
	Tree *t=new Tree();
	t->createSegTree(A,n);
	for(lli i=0;i<m;i++){
		cin>>a>>b>>c;

	}
	calculate_fibonacci();
	return 0;
}