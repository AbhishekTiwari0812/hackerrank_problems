#include <set>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    int temp,num;
    cin>>n;
    int **A=new int*[n];
    set<int> stud;
    for(int i=0;i<n;i++){
        cin>>temp;
        stud.insert(temp);
        cin>>num;
        A[i]=new int[num+1];
        A[i][0]=num;
        for(int j=0;j<num;j++){
            cin>>temp;
            A[i][j+1]=temp;
        }
    }
    int count=0;
    set<int>subs;
    for(int i=0;i<n;i++){
        int size=A[i][0];
        for(int j=1;j<size+1;j++){
            //cout<<"student:"<<A[i][j]<<" ";
            if(stud.find(A[i][j])==stud.end() && subs.find(A[i][j])==subs.end()){
                subs.insert(A[i][j]);
                count++;
            }
           // else cout<<"not found"<<endl;
        }

    }
    cout<<count<<endl;
    return 0;
}
