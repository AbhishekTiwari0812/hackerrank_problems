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

struct p{
	int x;
	int y;
	int z;

};
p con(int a,int b,int c){
	p temp;
	temp.x=a;
	temp.y=b;
	temp.z=c;
	return temp;
}

class cmp{
public:
	bool operator()(const p &a,const p &b)const{
		if(a.x==b.x){
			if(a.y == b.y){
				return a.z < b.z;
			}
			else return a.y < b.y;
		}
		else return a.x < b.x;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
    /*if(n==1){
        cout<<1<<endl<<0<<' '<<0 <<' '<<1<<endl;
        return 0;
    }
    else if(n==2){
        cout<<1<<endl<<0<<' '<<0 <<' '<<2<<endl;
        return 0;
    }*/
	set<p,cmp> s;
	fr(i,2*n/3,0)
		fr(j,2*n/3,0)
			if(i+j <= n && n-i-j <=2*n/3)
				s.insert(con(i,j,n-i-j));
			else break;
	f(i,0,2*n/3)
		f(j,0,2*n/3)
			if(i+j <= n && n-i-j <=2*n/3)
				s.insert(con(i,j,n-i-j));
			else break;
	si ans1,ans2,ans3;
	set<p,cmp> ans;
	for(set<p,cmp>::iterator it = s.begin(); it!=s.end(); ++it){
		p temp = (*it);
		if(temp.x != temp.y && temp.x != temp.z && temp.y != temp.z){
			if(ans1.find(temp.x)==ans1.end() && ans1.find(temp.y)==ans1.end() && ans1.find(temp.z)==ans1.end() ){
				ans.insert(temp);
				ans1.insert(temp.x);
				ans1.insert(temp.y);
				ans1.insert(temp.z);
			}
		}
	}
	ll final_ans = ans.size()*3;
	si test;
	for(set<p,cmp>::iterator it = ans.begin(); it!=ans.end(); ++it){
		test.insert(it->x);
		test.insert(it->y);
		test.insert(it->z);
	}
	for(int i=0;i<n;++i){
		if(test.find(i)!=test.end())
			continue;
		else{
			int k = n - 2*i;
			if(k < 0)
				continue;
			if(test.find(k)==test.end()){
				ans.insert(con(i,i,k));
				test.insert(k);
			}

		}
	}
	int new_ans = ans.size() - final_ans/3 + final_ans;
	cout<<new_ans<<endl;
	for(set<p,cmp>::iterator it = ans.begin(); it!=ans.end(); ++it){
		if(it->x != it->y){
			cout<<(it->x)<<' '<<(it->y)<<' '<<(it->z)<<'\n';
			cout<<(it->y)<<' '<<(it->z)<<' '<<(it->x)<<'\n';
			cout<<(it->z)<<' '<<(it->x)<<' '<<(it->y)<<'\n';
		}
		else{
			cout<<(it->x)<<' '<<(it->y)<<' '<<(it->z)<<'\n';
		}
	}

	return 0;
}