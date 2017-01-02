#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<string>
#include<set>
using namespace std;
#define f(iter,value_container,b) for(long long iter=value_container;iter<b;iter++)
#define fr(iter,value_container,b) for(long long iter=value_container;iter>=b;iter--)
#define ff(iter,value_container,b,c) for(int iter=value_container;iter<b;iter+=c)
#define vi vector<int>
#define MOD 1000000007
struct mystructure{
    long long my_index;
};
long long value_container[3*100005];
mystructure MY_BST_HELPER[4*3*100005+1];
vector<pair<long,long>> keep;
map<long long,long long> hash_table;
map<long long,long long> reverse_the_values;

void cst(long long current_left,long long current_right,long long element){
    if(current_left==current_right){
        MY_BST_HELPER[element].my_index=keep[current_left].second;
        return;
    }
    long long mid=(current_left+current_right)/2;
    cst(current_left,mid,2*element+1);
    cst(mid+1,current_right,2*element+2);
    MY_BST_HELPER[element].my_index=min(MY_BST_HELPER[2*element+1].my_index,MY_BST_HELPER[2*element+2].my_index);
}
long long find(long long TREE_LEFT,long long TREE_RIGHT,long long current_left,long long current_right,long long element)
{
    if(TREE_LEFT>current_right || TREE_RIGHT<current_left)
        return 1e18;
    if(current_left>=TREE_LEFT && current_right<=TREE_RIGHT)
        return MY_BST_HELPER[element].my_index;
    return min(find(TREE_LEFT,TREE_RIGHT,current_left,(current_left+current_right)/2,2*element+1),find(TREE_LEFT,TREE_RIGHT,1+(current_left+current_right)/2,current_right,2*element+2));
}
void FindAnswer(long long iter,long long iter_2,long long pos,long long Size){
    if(iter>iter_2)return;
    long long ind=find(iter,iter_2,0,Size-1,0);
    long long current_value=value_container[ind];
    long long my_index=reverse_the_values[current_value];
    if(current_value==-1)return;
    hash_table[current_value]=(pos%MOD);
    FindAnswer(iter,my_index-1,(2*pos)%MOD,Size);
    FindAnswer(my_index+1,iter_2,(2*pos+1)%MOD,Size);
}
int main()
{
    long long Size;
    cin>>Size;
    f(iter,0,Size){
        cin>>value_container[iter];
        keep.push_back(make_pair(value_container[iter],iter));
    }
    sort(keep.begin(),keep.end());
    f(iter,0,Size)
        reverse_the_values[keep[iter].first]=iter;
    cst(0,Size-1,0);
    FindAnswer(0,Size-1,1,Size);
    f(iter,0,Size)
        cout<<hash_table[value_container[iter]]<<" ";
}