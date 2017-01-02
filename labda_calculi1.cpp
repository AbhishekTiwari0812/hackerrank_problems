#include <unordered_map>
#include <iostream>
using namespace std;
int main(){
	sync_with_stdio(false);
	int t;
	cin>>t;5
251149 86127 711523 501067 617190
	unordered_map<int,int> m;
	int x,y;
	bool flag;
	while(t--){
		int n;
		flag=false;
		cin>>n;
		while(n--){
			cin>>x>>y;
			if(!flag){
				if(m.find(x)!=m.end()){
					if(m[x]!=y){
						flag=true;
					}
				}
				else
					m[x]=y;
			}

		}	
		if(!flag)
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}