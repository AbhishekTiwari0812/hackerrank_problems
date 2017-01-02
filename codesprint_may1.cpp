#include <iostream>

using namespace std;


int main(){
while(true){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int need[n];
	for(int i=0;i<n;i++)
		need[i]=0;
	int p = (n-1)/2;
	n = n/2;
	int len=s.length();
	while(p >= 0){
		if(s[p]==s[n]){
			need[p]=need[p+1];
		}else{
			need[p]=need[p+1]+1;
		}
		p--;
		n++;
	}
	if(need[0] > k)
		cout<<(-1)<<endl;
	else{
		for(int i=0;i<len;i++){
			if(s[i]==s[len-i-1]){
				if(k > need[i]+1 || (( i == (len-i-1))&&(k==1)) ){
					if(s[i]!='9'){
						s[i]='9';
						s[len-i-1]='9';
						k-=2;
					}
				}
			}
			else{
				if(k > need[i]){
					if(s[i]!='9'){
						s[i]='9';
						k--;
					}
					if(s[len-i-1]!='9'){
						s[len-i-1]='9';
						k--;
					}
				}
				else{
					char max_c=max(s[i],s[len-i-1]);
					s[i]=max_c;
					s[len-i-1]=max_c;
					k--;
				}
			}
		}
		cout<<s<<endl;
	}
	break;
}
	return 0;
}