#include <bits/stdc++.h>
using namespace std;

set<string> List;
string s;
int length;

string help(int n){
	int index = length-1;
	string my="";
	while(n > 0){
		if(n&1){
			my = s[index]+my;
		}
		n >>=1;
		index--;
	}
	return my;
}

void solve(){
    long n = (1 << length) ;
    for(int i=0;i<n;++i){
        string ans = help(i);
        List.insert(ans);
    }
}

void print(){
    for(set<string>::iterator it=List.begin();it!=List.end();++it){
        cout<<(*it)<<endl;
    }
}

int main(){
	int n;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	while(n--){
		cin>>s;
		length = s.length();
		solve();
		print();
        List.clear();
	}
}
