#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<b;++i)
using namespace std;
typedef vector<int> vi;
map<int,vi > m;

int n;
int bin_search(vi &A,int left,int right,int key){
	int mid=(left+right)/2;
	if(left < right - 1){
		if(key < A[mid])
			return bin_search(A,left,mid,key);
		else return bin_search(A,mid,right,key);
	}
	else{
		if(A[left] > key)
			return A[left];
		if(A[right] > key)
				return A[right];
		else return INT_MAX;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	int a[2*(int)1e5+10];
	int b[2*(int)1e5+10];
	cin>>n>>q;
	m.clear();
	f(i,0,n){
		cin>>a[i];
		if(m.find(a[i])==m.end()){
			vi temp_vector;
			m[a[i]]=temp_vector;
			m[a[i]].push_back(i);
		}
		m[a[i]].push_back(i);
	}
	int d;
	int index_end;
	int index_start;
	int temp_min_end;
	int min_len;
	f(i,0,q){
		cin>>d;
		//cout<<"Diff:"<<d<<endl;
		min_len=INT_MAX;
		f(i,0,n){
			//cout<<"Checking with a[i]:"<<a[i];
			int k = d+a[i];
			//cout<<" mod:"<<k<<endl;
			if(m.find(k)!=m.end()){
				temp_min_end=bin_search(m[k],0,m[k].size()-1,i);
				//cout<<"Found index:"<<temp_min_end;
				/*if(temp_min_end<n)
					cout<<" value:"<<a[temp_min_end]<<endl;*/
				if(temp_min_end - i < min_len){
					min_len=temp_min_end-i;
					index_end=temp_min_end;
					index_start=i;
				}
			}
		}
		if(min_len<(int)1e7)
            cout<<(index_start+1)<<' '<<(index_end+1)<<endl;
        else cout<<(-1)<<endl;
	}

	return 0;
}
