<<<<<<< HEAD
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define f(i,a,b) for( int i = ( a ); i < (b); ++i )
#define fr(i,a,b) for( int i = ( a ); i >= ( b ); --i )
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int>ii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef set<int> si;
typedef set<string> ss;
typedef set<ll> sl;
typedef set<ld> sd;
typedef map<string,int> msi;
typedef map<string,ll> msl;
typedef map<string,ld> msd;
typedef map<string,string> mss;
typedef map<int,string> mis;
typedef map<ll,string> mls;
typedef map<ld,string> mds;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int iter=5;
    int a[5],b[5];
    int ans=0;
    f(i,0,iter)
        cin>>a[i];
    f(i,0,iter)
        cin>>b[i];
    
    f(i,0,iter)
        ans+=min(abs(10-max(a[i],b[i])+min(a[i],b[i])),abs(a[i]-b[i]));
    cout<<ans<<endl;
    return 0;
}



=======
#include <iostream>
#include <set>
using namespace std;


set<char> MP;

void exchange(string &s,int i,int j){
	char temp=s[i];
	s[i]=s[j];
	s[j]=temp;
}
void char_swap(string &s){
	int l=s.length();
	int start=0;
	int end=l-1;
	while(start < end){
		if( MP.find(s[start])!=MP.end()){
			start++;
			continue;
		}
		if( MP.find(s[end])!=MP.end()){
			end--;
			continue;
		}
		exchange(s,start,end);
        start++;
        end--;
    }
}

int main(){
	int t;
	ios_base::sync_with_stdio(false);
	MP.insert('e');
	MP.insert('a');
	MP.insert('i');
	MP.insert('o');
	MP.insert('u');
	cin>>t;
	string s;
	while(t--){
		cin>>s;
		char_swap(s);
		cout<<s<<endl;
	}
}
>>>>>>> edcbdab16873cb7cba4478ee18f05d989cec02c9
