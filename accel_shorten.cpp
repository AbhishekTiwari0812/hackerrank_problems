#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string s;
    cin>>s;
    int x=0;
    int y=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='E')
            x+=1;
        else if(s[i]=='W')
            x-=1;
        else if(s[i]=='N')
            y+=1;
        else y-=1;
    }
    
    if(x>=0 && y >= 0){
        for(int i=0;i<x;i++)
            cout<<"E";
        for(int i=0;i<y;i++)
            cout<<'N';
    }
    else if(x>=0 && y < 0){
        for(int i=0;i<x;i++)
            cout<<"E";
        for(int i=0;i<(-y);i++)
            cout<<'S';
    }
    else if(x<0 && y >= 0){
        for(int i=0;i<y;i++)
            cout<<'N';

        for(int i=0;i<(-1*x);i++)
            cout<<'W';
    }
    else if(x<0 && y < 0){
        for(int i=0;i<(-y);i++)
            cout<<'S';
        for(int i=0;i<(-x);i++)
            cout<<'W';
    }
    cout<<endl;
    return 0;
}