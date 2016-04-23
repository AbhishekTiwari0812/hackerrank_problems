#include <iostream>
using namespace std;
typedef long long int lli;
typedef long double ld;



int MOD =1000000007;
lli *f;
void calc(int n){
	f=new lli[n+1];
	f[0]=1;
	f[1]=1;
	for(int i=2;i<=n;i++){
		f[i]=(i*f[i-1])%MOD;
	}
}

lli pow(int base,int power){
	if(power==1)
		return base;
	if(power==0)
		return 1;
	lli half=pow(base,power/2);
	if(power%2==1)
		return (half*((half*base)%MOD))%MOD;
	else return (half*half)%MOD;
}
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	//cin>>t;
	t=1;
	while(t--){
        lli m,n;
		cin>>n>>m;
		calc(m);
		lli answer=1;
		for(int i=1;i<m;i++){
			answer = (answer*f[i])%MOD;
		}
		answer%=MOD;
		answer=pow(answer,2)%MOD;
		answer =(answer*(pow(f[m],n-m+1)%MOD))%MOD;
		cout<<answer<<endl;
	}

	return 0;
}
