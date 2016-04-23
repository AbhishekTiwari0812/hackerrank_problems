#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
typedef long long int lli;
typedef long double ld;
using namespace std;
string reduce(string s){
  //  cout<<"call to functions.s="<<s<<endl;
	string new_string="";
	int count=0;
	int i=0;
	int l=s.length();
	while(i<(l)){
		if((i!=l-1 )&&(s[i]==s[i+1])){
            count++;
			i+=2;
		}
		else {
			new_string+=s[i];
            i+=1;
		}
	}
	//cout<<new_string<<endl;
	s=new_string;
	if(count==0)
		return s;
	else return reduce(s);

}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	t=1;
	while(t--){
		string s;
		cin>>s;
		string new_string=reduce(s);
		if(new_string.length()==0)
			cout<<"Empty String"<<endl;
		else cout<<new_string<<endl;
	}
	return 0;
}
