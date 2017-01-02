#include <bits/stdc++.h>
#define mod ((int)(1e9 ) + 7 )
using namespace std;
string food;
string sleep;
int n;

int *zeros;
int **char_count;
int **pair_count;


void init(){
	zeros = new int[n];
	zeros[0] = (sleep[0] == '0' ? 1 : 0);
	for(int i = 1; i < n; ++i){
		zeros[i] = zeros[i-1] +  (sleep[i] == '0' ? 1 : 0);
	}
	char_count = new int*[n];
	for(int i = 0; i < n; ++i){
		char_count[i] = new int[26];
	}
	for(int i = 0; i < 26; ++i){
		char_count[0][i] = 0;
	}
	char_count[0][food[0]-'a']++;
	for(int i = 1; i < n; ++i){
		for(int j = 0; j < 26; ++j){
			char_count[i][j] = char_count[i-1][j];
		}
		char_count[i][food[i]-'a']++;
	}
	pair_count = new int*[n];
	for(int i = 0; i < n; ++i){
		pair_count[i] = new int[52];
	}

	for(int i = 0; i < 52; ++i){
		pair_count[0][i] = 0;
	}
	
	pair_count[0][food[0]-'a' + 26*(sleep[0]-'0')]++;
	for(int i = 1; i < n; ++i){
		for(int j = 0; j < 52; ++j){
			pair_count[i][j] = pair_count[i-1][j];
		}
		pair_count[i][food[i]-'a' + 26*(sleep[i]-'0')]++;
	}
}

int count_zeros(int l, int r){
	if(l == 0)
		return zeros[r];
	else return zeros[r] - zeros[l-1];
}

int count_chars(int l, int r, int pos, bool flag){
	if(flag){
		if( l == 0){
			return char_count[r][pos];
		}
		else {
			char_count[r][pos] - char_count[l-1][pos];
		}
	}
	else{
		if( l == 0){
			return pair_count[r][pos];
		}
		else {
			pair_count[r][pos] - pair_count[l-1][pos];
		}	
	}
}

long c2(int k){
	return ((long) k * ((long) k - 1)) / 2;
}

void solve(int l,int r){
	long long ans = 0;
	int zero_count = count_zeros(l,r);
	int ones = r - l + 1 - zero_count;
	ans += c2(zero_count);
	ans += c2(ones);
	for(int i=0;i<26;++i){
		ans += c2(count_chars(l,r,i,true));
	}
	for(int i=0;i<52;++i){
		ans -= c2(count_chars(l,r,i,false));
	} 
	cout<<ans<<endl;
}

int main(){
	cin>>n>>food>>sleep;
	int q;
	init();
	cin>>q;
	int l,r;
	while(q--){
		cin>>l>>r;
		--l;
		--r;
		solve(l,r);
	}
	return 0;
}