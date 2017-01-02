#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<b;++i)
#define fr(i,a,b) for(int i=a;i>=b;--i)

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef set<string> ss;
typedef map<int,string> mis;
typedef map<string,string> mss;
typedef map<ll,ll> mll;


void solve(string current, string remaining){
	if(remaining == "xxxxxxxxx"){
		//try_ans(current);
		//cout<<current<<endl;
	}
	else{
		f(i,0,remaining.length()){
		    if(remaining[i]=='x')
                continue;
			string new_remain = remaining;
			new_remain[i]='x';
			string new_current=current + remaining[i];
			solve(new_current,new_remain);
		}
	}
}

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int inbuilt[3][3];
	/*f(i,0,3)
		f(j,0,3)
			cin>>inbuilt[i][j];
	*/
	string num="123456789";
	solve("",num);
	return 0;
}
