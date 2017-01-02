#include <bits/stdc++.h>
#define f(i,a,b) for(int i=(a),__=(b);i<__;++i)
using namespace std;
int n;
string s;

bool not_fit(int a[],int b[]){
	f(i,0,4)
		if(a[i] < b[i])
			return true;
	return false;
}

void solve(){
	int min=INT_MAX;
	int a[4];
	int require[4];
	memset(a,0,sizeof(a));
	memset(require,0,sizeof(require));
	f(i,0,n)
		a[s[i]-'a']++;
	f(i,0,4)
		require[i]=( a[i] - n / 4 ) > 0 ? ( a[i] - n / 4 ) : 0;
	int start=0,end=-1;
	int current_min;
	int count[4];
	memset(count,0,sizeof(count));
	while(1){
		f(i,0,(int)1e6);
		if(not_fit(count,require)){
			end++;
			if(end >= n)
				break;
			count[s[end]-'a']++;
			/*cout<<"Increasing end:"<<end<<endl;
			f(i,0,4)
				cout<<count[i]<<' ';
			cout<<endl;*/
		}
		else{
			current_min = end-start+1;
			if(current_min < min)
				min=current_min;
            if(start >= n )
                break;
			count[s[start]-'a']--;
			start++;
			/*cout<<"Increasing start:"<<start<<endl;
			f(i,0,4)
				cout<<count[i]<<' ';
			cout<<endl;*/
		}

	}
	cout<<min<<endl;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	char c;
	cin>>s;
	f(i,0,n){
		c=s[i];
		if(c=='A')
			s[i]='a';
		else if(c=='G')
			s[i]='b';
		else if(c=='C')
			s[i]='c';
		else if(c=='T')
			s[i]='d';
	}
	solve();
	return 0;
}
