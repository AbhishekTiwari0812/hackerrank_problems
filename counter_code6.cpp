#include<stdlib.h>
#include<iostream>
using namespace std;

typedef struct TreeNode{
	int count=0;
	int val=0;
	struct TreeNode *left=NULL;
	struct TreeNode *right=NULL;
} node;



class Tree{
	public:
		node *head;
		int TotalCount;
		void Insert(int num);
		void Delete(int num);
		void GetCount(node *a,int b);
		void CreateTree(node *a,int b);
		void setHead(){
			head=(node *)malloc(sizeof(node));
		}
};

void Tree::Insert(int num){
	node *temp=head;
	while(num>0){
		if(num%2==1)
			temp=temp->right;
		else
			temp=temp->left;
		num/=2;
	}
	temp->count+=1;
}

void Tree::Delete(int num){
	node *temp=head;
	while(num>0){
		if(num%2==1)
			temp=temp->right;
		else
			temp=temp->left;
		num/=2;
	}
	temp->count-=1;
}

void Tree::GetCount(node *head,int num){
	if(num%2==head->val){
		TotalCount+=head->count;
		if(head->left!=NULL)
			GetCount(head->left,num/2);
		if(head->right!=NULL)
			GetCount(head->right,num/2);
	}
}



void Tree::CreateTree(node *head,int height){
	if(height<0);			//leaf level reached,do nothing!
	else {
		node *left=(node *)malloc(sizeof(node));
		node *right=(node *)malloc(sizeof(node));head->left=left;																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																		
head->right=right;
		CreateTree(left,height-1);
		head->left->val=0;
		CreateTree(right,height-1);
		head->right->val=1;

	}
}

int main(){
	Tree mTree;
	mTree.setHead();
	mTree.CreateTree(mTree.head,32);			//expected height of the tree	is 33.
	int Q; 
	string s;
	int num;
	for(int i=0;i<Q;i++){
		cin>>s;
		cin>>num;
		switch (s[0]){
		case 'a':		//add
			mTree.Insert(num);			
			break;
		case 'd':		//delete
			mTree.Delete(num);
			break;
		case 'c':		//count
			mTree.TotalCount=0;
			mTree.GetCount(mTree.head,num);
			cout<<mTree.TotalCount<<endl;			
			break;
		}
	}


	return 0;
}
