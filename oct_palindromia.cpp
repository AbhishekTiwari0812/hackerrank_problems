#include <bits/stdc++.h>
using namespace std;
typedef string s;

bool is_pal(string &s){
	int l = s.length();
	for(int i = 0; i < l/2; ++i )
		if(s[i] != s[l-i-1])
			return false;
	return true;
}

void rev(string &s,int i,int j){
	int mid = ( j - i + 1 ) / 2;
	for(int k = 0; k < mid; ++k){
		char temp = s[k + i];
		s[k + i] = s[j - k];
		s[j - k] = temp;
	}
}

int check(string s,int k){
	if(!k){
		if(is_pal(s))
			return true;
		else
		return false;
	}
	else if(k == 1){
		int l = s.length();
		for(int i=0; i < l; ++i){
			for(int j=i+1; j < l; ++j){
				string cpy = s;
				rev(cpy, i, j);
				if(is_pal(cpy)){
					return true;
				}
			}
		}
		return false;
	}
	else if( k == 2){
		int l = s.length();
		for(int i=0; i < l-3; ++i){
			for(int j = i+1; j < l-2; ++j){
				string cpy = s;
				rev(cpy,i,j);
				for(int x = j+1; x < l-1;++x){
					for(int y = x+1; y < l;++y){
						rev(cpy,x,y);
						if(is_pal(cpy))
							return true;
					}
				}
			}
		}
		return false;
	}
}


int main(){
	int n,l;
	cin>>n>>l;
	int count = 0;
	string s;
	for(int i=0; i < n; ++i ){
		cin>>s;
		if(check(s,0)){
			count++;
			continue;
		}
		if(check(s,1)){
			count++;
			continue;
		}
		if(check(s,2)){
			count++;
			continue;
		}
	}
	cout<<count<<endl;
	return 0;
}