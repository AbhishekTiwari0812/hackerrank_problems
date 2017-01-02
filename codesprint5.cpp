#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#define f(i,a,b) for(long long i=a;i<b;i++)
#define fr(i,a,b) for(long long i=a;i>=b;i--)
#define  MAX_LIMIT 10000040
#define alpha_limit 26
using namespace std;
long long MyBadTable[MAX_LIMIT];
long long character_checker[alpha_limit];

void solve(string input_string,int k){
    int n=input_string.length();
    long long position=0;
    f(i,0,alpha_limit)
        character_checker[i]=1000000000000;
    fr(i,n-1,0){
        MyBadTable[i]=0;
        long long post_operator=1000000000000;
        fr(j,25,0){
            if(input_string[i]<(char)(((int)'a')+j))
                post_operator=min(post_operator,character_checker[j]);
        }
        if(post_operator!=1000000000000)
            MyBadTable[i]=post_operator;
        character_checker[input_string[i]-((int)'a')]=i;
    }
    string final_answer="";
    long long i=0;
    long long value_finder=k;
    for(i=0;i<n;i++){
        if(final_answer.length()==input_string.length()-value_finder)break;
        if(MyBadTable[i]==0){
            position=i;
            final_answer+=input_string[i];
        }
        else
        {
            if(MyBadTable[i]-i<=k)
            {
                k=k-(MyBadTable[i]-i);
                i=MyBadTable[i]-1;
            }
            else
                final_answer+=input_string[i];
        }
        if(k<=0)break;
    }
    f(j,i+1,n)
    {
        if(final_answer.length()==input_string.length()-value_finder)break;
        final_answer+=input_string[j];
    }
    cout<<final_answer<<endl;

}
int main(){
    int t;
    ios_base::sync_with_stdio(false);
    cin>>t;
    string input_string;
    int k;
    while(t>0){
        t--;
        cin>>input_string;
        cin>>k;
        solve(input_string,k);
    }
}