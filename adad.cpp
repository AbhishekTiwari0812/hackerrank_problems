#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<string> v;
	for(int i=0;i<n;i++){
		string given="";
		cin>>given;
		for(int j=0;j<(1<<given.length());j++){
			string t="";
			for(int k=0;k<given.length();k++){
				if((1<<k)&j)t+=given[k];
			}
			if(t!="")
			v.push_back(t);
		}
		sort(v.begin(),v.end());
		for(int j=0;j<v.size();j++)cout<<v[j]<<endl;
		v.clear();
	}
}
