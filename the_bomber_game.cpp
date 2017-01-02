#include <bits/stdc++.h>
#define f(i,a,b) for(int i=(a),__=(b); i < __; ++i)
#define fr(i,b,a) for(int i=(b), __ = ( a ); i >= __; --i)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef set<string> ss;

int r,c,n;
char table[204][204];
char table1[204][204];

void get_next(){
    f(i,0,r)
		f(j,0,c)
			table1[i][j]='x';
	f(i,0,r)
		f(j,0,c){
			if(table[i][j] == 'O'){
				table1[i][j]='.';
				int x,y;
				x=i+1;
				y=j;
				if(x >=0 && x < r && y >=0 && y < c)
					table1[x][y]='.';
				x=i-1;
				y=j;
				if(x >=0 && x < r && y >=0 && y < c)
					table1[x][y]='.';
				x=i;
				y=j+1;
				if(x >=0 && x < r && y >=0 && y < c)
					table1[x][y]='.';
				x=i;
				y=j-1;
				if(x >=0 && x < r && y >=0 && y < c)
					table1[x][y]='.';

			}
		}
    f(i,0,r)
		f(j,0,c)
            if(table1[i][j]!='.')
                table1[i][j]='O';
}

bool cmp(){
    f(i,0,r){
        f(j,0,c)
            if(table1[i][j] != table[i][j])
                return false;
    }
    return true;
}
void copy(){
    f(i,0,r)
        f(j,0,c)
            table[i][j]=table1[i][j];
}

void print_tb(bool flag){
    f(i,0,r){
        f(j,0,c)
        	if(flag)
        		cout<<'O';
            else
            	cout<<table[i][j];
        cout<<endl;
    }
}

void solve(){
    int count=0;
    if(n%2==0)
    	print_tb(true)
    while(true){
        count++;
        if(n==count)
            break;
        get_next();
        copy();
        count++;
        if(count==n)
            break;
        if(cmp())
            break;
    }
    print_tb(false);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>r>>c>>n;
	string s;
	f(i,0,r){
		cin>>s;
		f(j,0,c)
			table[i][j]=s[j];
	}
	solve();
	return 0;
}
