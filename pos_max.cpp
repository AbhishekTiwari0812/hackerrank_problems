#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define some 1000000
using namespace std;



int closest_bigger(vector<int> v){
	for(int i=0;i<v.size();i++)
		if(v[i]==0){
			v[i]=1;
			return bin_to_num(v);
		}
	return (bin_to_num(v)<<1)+1;
}

int bin_to_num(vector<int> &a){
	int num=0;
	int pow=1;
	for(int i=0;i<a.size();i++){
		num+=a[i]*pow;
		pow=pow<<1;
	}
	return num;
}

vector num_to_bin(int num){
	vector<int> bin;
	while(num>0){
		bin.push_back(num%2);
		num=num>>1;
	}
	return bin;
}


int close_min(vector<int> &v){
	for(int i=0;i<v.size()i++)
		if(v[i]==1){
			v[i]=0;
			return bin_to_num(v);
		}
}

int main() {
    int test;
    int n,k;
    int num_of_bits;
    int help;
    int a;
	 
    cin>>test;
    for(int i=0;i<test;i++){
	    cin>>n>>k;
		 if(k-1<n){
				while(true){
					//can be made more efficient here
					vector<int> v=num_to_bin(k-1);		
					a=closest_bigger(v);
					if(a <= n){
						cout<<a<<endl;
						break;	
					}
					else k-=1;
				}
		 }
		 else if(k-1>=n){
			vector<int> v=num_to_bin(n);	
			cout<<close_min(v)<<endl;	
		 	
		 }
		 		    
    }
    return 0;
}
