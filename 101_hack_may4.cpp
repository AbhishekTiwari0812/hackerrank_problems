#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

struct node{
    int value;
    set<int> nbd;
};

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    node a[n];
    node b[n];
    node c[n];
    int u,v;
    for(int i=0;i<n;i++){
        a[i].value=i;
        b[i].value=i;
        c[i].value=i;
    }
    for(int i=0;i<3;i++){
        int s;
        cin>>s;
        if(i==0)
        for(int j=0;j<s;j++){
            cin>>u>>v;
            u-=1;
            v-=1;
            a[u].nbd.insert(v);
            a[v].nbd.insert(u);
            
        }
        else if(i==1)
        for(int j=0;j<s;j++){
            cin>>u>>v;
            u-=1;
            v-=1;
            b[u].nbd.insert(v);
            b[v].nbd.insert(u);
        }
        else if(i==2)
        for(int j=0;j<s;j++){
            cin>>u>>v;
            u-=1;
            v-=1;
            c[u].nbd.insert(v);
            c[v].nbd.insert(u);
        }
                
    }
    
    int count=0;
    set<int>::iterator it,it2;
    for(int i=0;i<n;i++){
        for(it=a[i].nbd.begin();it!=a[i].nbd.end();it++){
            int temp=(*it);     //b
            for(it2=b[temp].nbd.begin();it2!=b[temp].nbd.end();it2++){
                int t2=(*it2);
                if(c[t2].nbd.find(a[i].value)!=c[t2].nbd.end())
                    count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}
