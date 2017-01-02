#include <iostream>
using namespace std;

int main(){
	int n;
	int a[(int)3e5];
	cin>>n;
	long count = 0;
	long count2 = 0;
	long count3 = 0;
	long ans = 0;
	for(int i = 0; i < n; ++i ){
		cin >> a[i];
		if( a[i] == 1 )
			count++;
		else if(a[i] == 2)
			count2++;
		else if(a[i] == 3)
			count3++;
	}
	long count4 = n - (count + count2 + count3);

	ans += (count4+count3) * ((count*count-1)/2);
	ans += 2 * (count2) *((count*count-1)/2);
	ans += count3*count2*count;
	ans += (count*(count-1)*(count-2))/2;
	cout<<ans<<endl;

	return 0;
}