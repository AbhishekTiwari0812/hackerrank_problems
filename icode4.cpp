#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define f(i,a,b) for( long long i = ( a ); i < (b); ++i )
#define fr(i,a,b) for( long long i = ( a ); i >= ( b ); --i )
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<long long,long long>ii;
typedef vector<long long> vi;
typedef vector<string> vs;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef set<long long> si;
typedef set<string> ss;
typedef set<ll> sl;
typedef set<ld> sd;
typedef map<string,long long> msi;
typedef map<string,ll> msl;
typedef map<string,ld> msd;
typedef map<string,string> mss;
typedef map<long long,string> mis;
typedef map<ll,string> mls;
typedef map<ld,string> mds;

struct inter{
	long long s;
	long long e;
	long long c;
	bool imp;
};

bool cmp(inter a, inter b){
	if(a.s != b.s)
		return a.s < b.s;
	else return a.e < b.e;
}

bool check(std::vector<inter> &v){
	for(long long i=0;i<v.size();++i){
		for(long long j = 0;j < v.size(); ++j){
			if(i!=j){
				if(v[i].s < v[j].e && v[i].s > v[j].s){
					return false;
				}
			}
		}
	}
	return true;
}

bool collide(inter a, vector<inter> &b){
	for(long long i=0; i < b.size(); ++i){
		if(a.s > b[i].s && a.s < b[i].e){
            return true;
        }
        else if(a.e >  b[i].s && a.e < b[i].e){
            return true;
        }
        else if(b[i].s >  a.s && b[i].e < a.e){
            return true;
        }
	}
	return false;
}

bool jobComparataor(inter s1, inter s2){
    return (s1.e < s2.e);
}

long long latestNonConflict(inter *arr, long long i){
    for (long long j=i-1; j>=0; j--){
        if (arr[j].e <= arr[i].s)
            return j;
    }
    return -1;
}

long long findMaxProfit(inter *arr, long long n){
    sort(arr, arr+n, jobComparataor);
    long long *table = new long long[n];
    table[0] = arr[0].c;
    for (long long i=1; i<n; i++) {
        long long inclProf = arr[i].c;
        long long l = latestNonConflict(arr, i);
        if (l != -1)
            inclProf += table[l];
        table[i] = max(inclProf, table[i-1]);
    }
    long long result = table[n-1];
    delete[] table; 
    return result;
}

vector<inter> trim(vector<inter> &a, vector<inter> &b){
	vector<inter> ans;
	for(long long i=0;i<a.size();++i){
		if(collide(a[i],b));
		else
			ans.pb(a[i]);
	}
	return ans;
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long t;
	cin>>t;
	vector<inter> Imp;
	vector<inter> current;
	while(t--){
		long long n;
		cin>>n;
		long long s;
		long long e;
		long long c;
		long long imp_gain=0;
		char imp;
		f(i,0,n){
			cin>>s>>e>>c>>imp;
			e += s;
			inter temp;
			temp.s=s;
			temp.e=e;
			temp.c=c;
			if(imp == 'I'){
				imp_gain += c;
				Imp.pb(temp);
			}
			else{
				current.pb(temp);
			}
		}
		sort(all(current),cmp);
		sort(all(Imp),cmp);
		if(check(Imp)){
			vector<inter> ans;
			ans = trim(current,Imp);
			inter * helper = new inter[ans.size()];
			f(j,0,ans.size()){
				helper[j] = ans[j];
			}
			long long temp_ans = findMaxProfit(helper,ans.size());
			cout<<(temp_ans+imp_gain)<<endl;
		}
		else{
			cout<<(-1)<<endl;
		}
		
		Imp.clear();
		current.clear();
	}

	return 0;
}