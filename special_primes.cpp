#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

ll _sieve_size;
bitset<10000010> bs;
set<int> primes;

void sieve(ll upperbound) {
	_sieve_size = upperbound + 1;
	bs.reset(); bs.flip();
	bs.set(0, false); bs.set(1, false);
	for (ll i = 2; i <= _sieve_size; i++) if (bs.test((size_t)i)) {
		for (ll j = i * i; j <= _sieve_size; j += i) bs.set((size_t)j, false);
			primes.insert((int)i);
	}
}

map<int,int>m;
int solve(int n){
	int new_num = 2*n+1;
	if(m.find(new_num)!=m.end())
		return m[new_num]+1;
	if(primes.find(new_num)==primes.end())
		return 0;
	int k=1+solve(new_num);
	m[n]=k;
	return k;
}


int main(){
	sieve((int)3e6);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    if(k > 6)
        return 0;
    int temp;
    for(set<int>::iterator it = primes.begin(); it!=primes.end() && (*it) <= n; ++it){
    	temp = (*it);
    	//cout<<"FOR temp="<<temp<<endl;
    	int ans = solve(temp);
    	//cout<<"ANS:"<<ans<<endl;
    	if(ans >= k)
    		cout<<temp<<' ';
    }
	return 0;
}
