#include <iostream>
using namespace std;
typedef long long int lli;

lli find_xor(lli a){
	if(a==0)
		return 0;
	switch(a%8){
		
		case 0:
			return a;
		break;
		case 1:
			return a;
		break;
		case 2:
			return 2;
		break;

		case 3:
			return 2;
		break;
		case 4:
			return a+2;
		break;
		case 5:
			return a+2;
		break;

		case 6:
			return 0;
		break;
		case 7:
			return 0;
		break;
	}
    return 0;
}

int main(){
	int n;
	cin>>n;
	lli p,q;
	lli answer;
	for(int i=0;i<n;i++){
		cin>>p>>q;
		cout<<(find_xor(p-1)^find_xor(q))<<endl;

	}
	return 0;
}
