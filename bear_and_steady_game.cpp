#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void p(int *a){
    for(int i=0;i<4;i++)
        cout<<a[i]<< " ";
    cout<<endl;
}

bool check(int *a,int *b){
    for(int i=0;i<4;i++)
        if(a[i] > b[i])
            return false;
 //   cout<<"match"<<endl;
    
  //  cout<<"needed:";
   // p(a);
    //cout<<"got:";
    //p(b);
        return true;
}
int solve(string s,int *extra){
    int c[4];
    for(int i=0;i<4;i++)
        c[i]=0;
    int min=(int)1e7;
    int start=0;
    int current_min;
    int end=0;
  //  p(extra);
   // p(c);
    if(check(extra,c))
        return 0;
    int l;
    while(true){
        c[s[end]-'a']++;
        if(check(extra,c)){
          l=end-start+1;
          if(l<min)
              min=l;
           while(true){
            //   cout<<"matched\n";
               if(start>end)
                   break;
               c[s[start]-'a']--;
               start++;
               if(check(extra,c)){
              //     cout<<"reducing..\n";
                   l=end-start+1;
                   if(l<min)
                       min=l;
               }
               else break;
           }
        }
        end++;
        if(end==s.length())
            break;
    }
    return min;
}
int main() {
    int l;
    cin>>l;
    string s;
    cin>>s;
    int count[4];
    for(int i=0;i<4;i++)
        count[i]=0;
    for(int i=0;i<l;i++){
        if(s[i]=='A'){
            s[i]='a';
            count[0]++;
        }
        else if(s[i]=='C'){
            s[i]='b';
            count[1]++;
        }
        else if(s[i]=='T'){
            s[i]='c';
            count[2]++;
        }
        else{
            s[i]='d';
            count[3]++;
        }
    }
    int v[4];
    for(int i=0;i<4;i++){
        if(count[i]>l/4)
            v[i]=count[i]-l/4;
        else v[i]=0;
    }
    cout<<solve(s,v)<<endl;
    return 0;
}
