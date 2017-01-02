#include <climits>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int biggest;
    int smallest;
    int value;
    int diff;
    int left_index;
    int right_index;
    node *parent;
    node *left;
    node *right;
};
node *create_node(int value){
	node *temp=new node;
    temp->smallest=value;
    temp->biggest=value;
    temp->diff=0;
	temp->left=NULL;
	temp->right=NULL;
    temp->parent=NULL;
	return temp;
}

class SegTree{
public:
    node *root;
    int *values;    // input array
    int size;       //size of the array
    void CreateTree();
    void update();
};
node *add_node(int *A,int left,int right){
    if(left==right){
        node *temp= create_node(A[left]);
        temp->left_index=left;
        temp->right_index=right;
        return temp;
    }
    else{
        int mid=(left+right)/2;
        node *current=new node;
        node *left_node=add_node(A,left,mid);
        node *right_node=add_node(A,mid+1,right);
        left_node->parent=current;
        right_node->parent=current;
        current->left=left_node;
        current->right=right_node;
        current->left_index=left_node->left_index;
        current->right_index=right_node->right_index;
        current->smallest=min(current->left->smallest,current->right->smallest);
        current->biggest=max(current->left->biggest,current->right->biggest);
        current->diff= max(current->right->biggest-current->left->smallest,max(current->left->diff,current->right->diff));
        return current;
    }
}
void SegTree::CreateTree(){
    this->root=add_node(this->values,0,this->size);
}

void update_value(node *current,int index,int value){
    if(current->left==current->right){
        current->smallest=value;
        current->biggest=value;
        current->diff=0;
    }
    else{
        int mid=(current->left_index+current->right_index)/2;
        if(index <= mid)
            update_value(current->left,index,value);
        else
            update_value(current->right,index,value);
        current->smallest=min(current->left->smallest,current->right->smallest);
        current->biggest=max(current->left->biggest,current->right->biggest);
        current->diff= max(abs(current->right->biggest-current->left->smallest),max(current->left->diff,current->right->diff));
    }

}
int get_value(node *current,int left,int right){
    if(current->left_index==left && current->right_index==right)
        return current->diff;
    else{
        int mid=(current->left_index+current->right_index)/2;
        if(right <= mid){
            return get_value(current->left,left,right);
        }
        else if(left > mid){
            return get_value(current->right,left,right);
        }
        else{
            return get_value(current->left,left,mid)+get_value(current->right,mid+1,right);
        }
    }

}

void print(node *root){
    if(root->left==NULL && root->right==NULL)
        printf("%d ",root->smallest);
    else{ 
        print(root->left);
        print(root->right);
    }
}

int main() {
    int n;
    cin>>n;
    int *A=new int[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    SegTree *T=new SegTree;
    T->values=A;
    T->size=n;
    T->CreateTree();
    int Q;
    cin>>Q;
    while(Q--){
        char c;
        int x,y;
        cin>>c>>x>>y;
        if(c=='V'){
            cout<<get_value(T->root,x,y)<<endl;
        }
        else{
            update_value(T->root,x,y);
            print(T->root);
            printf("\n");
        }

    }
    return 0;
}
