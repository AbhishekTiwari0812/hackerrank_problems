#include <iostream>
#include <set>
using namespace std;


set<char> MP;

void exchange(string &s,int i,int j){
	char temp=s[i];
	s[i]=s[j];
	s[j]=temp;
}
void char_swap(string &s){
	int l=s.length();
	int start=0;
	int end=l-1;
	while(start < end){
		if( MP.find(s[start])!=MP.end()){
			start++;
			continue;
		}
		if( MP.find(s[end])!=MP.end()){
			end--;
			continue;
		}
		exchange(s,start,end);
        start++;
        end--;
    }
}

int main(){
	int t;
	ios_base::sync_with_stdio(false);
	MP.insert('e');
	MP.insert('a');
	MP.insert('i');
	MP.insert('o');
	MP.insert('u');
	cin>>t;
	string s;
	while(t--){
		cin>>s;
		char_swap(s);
		cout<<s<<endl;
	}
}