#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define MY_MOD (int)(1e9+7)
using namespace std;
typedef long long lli ;


long long pow(lli a, lli b, lli MOD)
{
    long long x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD; 
        b /= 2;
    }
    return x;
}
 
/*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m) */
long long InverseEuler(lli n, lli MOD)
{
    return pow(n,MOD-2,MOD);
}
 
long long C(lli n, lli r, lli MOD=MY_MOD){
	if( n<r || r< 0)
		return 0;
    vector<long long> f(n + 1,1);
    for (lli i=2; i<=n;i++)
        f[i]= (f[i-1]*i) % MOD;
    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}
 

int main(){
	lli rr,rb,bb,br;
	cin>>rr>>rb>>bb>>br;
	lli answer1,answer2,total_answer=0;
	lli num_of_places;
	if(abs(rb-br) > 1)
		cout<<0<<endl;
	else{
		if(rb-1 == br){
			num_of_places=rb;
			answer1=C(rb+rr-1,rr);
			num_of_places=rb;
			answer2=C(rb+bb-1,bb);
			total_answer=(answer2*answer1)%MY_MOD;
		}
		else if(rb+1==br){
			num_of_places=br;
			answer1=C(br+rr-1,rr);
			num_of_places=br;
			answer2=C(br+bb-1,bb);
			total_answer=(answer2*answer1)%MY_MOD;
		}
		else{
			total_answer=0;
			num_of_places=rb+1;
			answer1=C(num_of_places+rr-1,rr);
			num_of_places=rb;
			answer2=C(num_of_places+bb-1,bb);
			total_answer+=(answer1*answer2)%MY_MOD;
			num_of_places=rb+1;
			answer1=C(num_of_places+bb-1,bb);
			num_of_places=rb;
			answer2=C(num_of_places+rr-1,rr);
			total_answer+=(answer1*answer2)%MY_MOD;



		}
	}
	cout<<(total_answer%MOD)<<endl;
    return 0;
}
