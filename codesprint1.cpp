#include <iostream>

using namespace std;


int main(){
    int n;
    cin >> n;
    int temp;
    int num=0;
    for(int a_i = 0;a_i < n;a_i++){
       cin >> temp;
        num+=temp;
    }
    if(num&1)
        cout<<"No ";
    else cout<<"Yes ";
    cout<<num<<endl;
    return 0;
}
