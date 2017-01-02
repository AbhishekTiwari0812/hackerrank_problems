#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int a[26];
	for(int i=0;i<26;++i)
		a[i]=0;
	for(int i=0;i<s.length();++i)
		a[s[i]-'a']++;
	sort(a,a+26);
	for(int i=n-1;i>=1;i--){
		if(a[i]!=a[i-1]){
			a[i]--;
			break;
		}
	}
	for(int i=1;i<26;++i){
		if(a[i]!=a[i-1]){
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	return 0;
}