#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
#include <set>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
typedef long long ll;

void solve(string []input,int n){
    map<string ,vector<string> > table;
    map<string ,int > my_hash_table2;
    for(int i=0;i<n;i++){
        if(my_hash_table2[input[i]]!=0)
            continue;
        my_hash_table2[input[i]]=1;
        vector<char> checker;
        string  temp="";
        for(int j=0;j<input[i].length();j++){
            checker.push_back((char)input[i][j]);
        }
        sort(checker.begin(),checker.end());
        for(int j=0;j<input[i].length()j++){
            temp+=checker[j];
        }
        table[temp].push_back(input[i]);
    }
    map<string , vector<string > >::iterator it;
    for(it=table.begin();it!=table.end();it++){
        min_lex=max(min_lex,(int )table[it->first].size());
    }
    vector<pair<string,string>> vector_product;
    for(it=table.begin();it!=table.end();it++)
    {
        vector<string> pls;
        if((int )table[it->first].size()==min_lex)
        {
            for(int j=0;j<table[it->first].size();j++)
                pls.push_back(table[it->first][j]);
            sort(pls.begin(),pls.end());
            vector_product.push_back(make_pair(pls[pls.size()-1],it->first));
        }
    }
    sort(vector_product.begin(),vector_product.end());
    cout<<table.size()<<endl;
    for(int i=0;i<vector_product.size();i++){
        vector<string > last;
        string  gh=vector_product[i].second;
        for(int j=0;j<table[gh].size();j++){
            last.push_back(table[gh][j]);
        }
        sort(last.begin(),last.end());
        for(int j=0;j<last.size();j++)
          cout<<last[last.size()-j-1]<<" ";
        cout<<endl;
    }
}
int  main(){
    ios_base::sync_with_stdio(false);
    
    int  n,min_lex=0;
    cin>>n;
    string  input[n];
    for(int i=0;i<n;i++)
        cin>>input[i];
    solve(input,n);
    
}