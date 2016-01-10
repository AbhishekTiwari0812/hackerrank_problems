#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> get_all_substrings(string & a){
	vector<string> temp;
	for(int i=0;i<a.length();i++){
		string last="";
		for(int j=i;j<a.length();j++){
			last+=a[j];
			string v=last;
			temp.push_back(v);
		}
	}
	return temp;
}

 string sort_string(string &A){
    char *d=new char[A.length()+1];
    int i;
    for(i=0;i<A.length();i++)
        d[i]=A[i];
    d[i]='\0';
    sort(d,d+A.length());
    string str(d);
    return str;
}
int main(){
	int n;
	cin>>n;
	string s;
	vector<string> substrings;
	map<string,int> m;
	for(int i=0;i<n;i++){
		cin>>s;
		m.clear();
		substrings=get_all_substrings(s);
		for(int j=0;j<substrings.size();j++){
			substrings[j]=sort_string(substrings[j]);
			if(m.find(substrings[j])==m.end())
				m[substrings[j]]=1;
			else m[substrings[j]]++;
		}
		long long int answer=0;
		for(map<string,int>::iterator it=m.begin();it!=m.end();it++){
			answer+= ((it->second) * (it->second-1))/2;
		}
		cout<<answer<<endl;
	}
	return 0;
}
