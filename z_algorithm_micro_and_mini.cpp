#include <iostream>
using namespace std;
 
int *create_z_array(string &s){
    int n = s.length();
    int *z = new int[n+1];
    z[0] = n;
    int l = 0;
    int r = 0;
    int k;
    for (int i = 1; i < n; ++i){
        if (i > r){
            l = r = i;
            while (r<n && s[r-l] == s[r])
                r++;
            z[i] = r-l;
            r--;
        }
        else{
            k = i-l;
            if (z[k] < r-i+1)
                 z[i] = z[k];
            else{
                l = i;
                while (r<n && s[r-l] == s[r])
                    r++;
                z[i] = r-l;
                r--;
            }
        }
    }
    z[n] = 0;
    return z;
}
 

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin >> s;
        int *z = create_z_array(s);
        int count = 0;
        for(int i = 0; i < n; ++i){
            if(z[i] == n-i && z[n-i] == i)
                ++count;
        }
        cout<<count<<endl;
    }
    return 0;
}