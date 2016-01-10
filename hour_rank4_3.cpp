#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct point{
    lli sum;
    lli count;
};

struct comp {
    bool operator()(const point& a, const point& b) const {
        return (a.sum*10000+a.count) < (b.sum*10000 + b.count);
    }
};


map<point,bool,comp> DP;

lli Sa,Sb;
bool winner(vector<int> v,int index){
    
}

int main(){
    int T;
    cin >> T;
    for(int a0 = 0; a0 < T; a0++){
        int n;
        DP.clear();
        cin >> n;
        vector<int> number(n);
        int count3=0;
        Sa=0;
        Sb=0;
        int temp;
        for(int a_i = 0;a_i < n;a_i++){
            cin>>temp;
            if(temp%3==0)
                count++;
            else number.push_back(temp);
        }
        bool winner(number);
    }
    return 0;
}
