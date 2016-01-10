#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define SIZE 5000010

using namespace std;
int s[SIZE+2];
void create_string(){
 		s[0]=1;
 		s[1]=2;
 		s[2]=2;
        int curr_in=2;
        int size=3;
        int bit=1;
        int curr_num=2;
        while(size<SIZE){
            bit=1-bit;
            curr_num=bit+1;
            for(int j=0;j<s[curr_in];j++)
                s[size++]=curr_num;
            curr_in++;
        }
}

int One[SIZE];
int Two[SIZE];
void initialize(){
	int count=1;
	for(int i=1;i<SIZE;i++){
		if(s[i]==1){
			One[count]=One[count-1]+1;
		}
		else {
			One[count]=One[count-1];
		}
		count++;
	}

	count=1;
	for(int i=1;i<SIZE;i++){
		if(s[i]==2){
			Two[count]=Two[count-1]+1;
		}
		else {
			Two[count]=Two[count-1];
		}
		count++;
	}
}

int main() {
	One[0]=1;
	Two[0]=0;
    int t;
    cin>>t;
    create_string();
    initialize();
    for(int i=0;i<t;i++){
      	int c,n;
        cin>>c>>n;
        if(c==1){
        	cout<<One[n-1]<<endl;
        }   
        else if(c==2)
        	cout<<Two[n-1]<<endl;
        
        
    }
    
   
    return 0;
}
