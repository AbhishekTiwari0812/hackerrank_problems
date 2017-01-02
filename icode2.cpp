#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

ll _sieve_size; 
bitset<10000010> bs;
vi primes;
void sieve(ll upperbound) { 
	_sieve_size = upperbound + 1;
	bs.reset();
	bs.flip();
	bs.set(0, false);
	bs.set(1, false);
	for (ll i = 2; i <= _sieve_size; i++)
		if (bs.test((size_t)i)) {
			for (ll j = i * i; j <= _sieve_size; j += i)
				bs.set((size_t)j, false);
			primes.push_back((int)i);
		}
}


long factors(int N) {
	int PF_idx = 0;
	int PF = primes[PF_idx];		//optional
	int count=0;
	long ans=1;
	while (N != 1 && (PF * PF <= N)) { 
		count=0;
		while (N % PF == 0){
			N /= PF;
			count++;
		}
		ans *= count+1;
		facts.push_back(count);
		PF = primes[++PF_idx];
	}
	if (N != 1){
		ans *= 2;
		facts.push_back(1);
	}
	return ans;
}

int main(){
	sieve((int)1e5);
	int n;
	cin>>n;
	int a[n];
	int temp;
	for(int i=0;i < n;++i){
		cin>>temp;
		a[i] = factors(temp);
	}
	int m;
	cin>>m;
	sort(a,a+n);
	int days = 0;
	long sum = 0;
	for(int i=0;i<n;++i){
		sum += a[i];
		if(sum > m)
			break;
		else days++;
	}
	cout<<days<<endl;
	return 0;
}

