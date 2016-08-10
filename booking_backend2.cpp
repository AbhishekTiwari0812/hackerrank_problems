#include <bits/stdc++.h>
#define f(i,a,b) for(int i=(a); i < (b); ++i)

using namespace std;

typedef long double ld;
typedef long long int ll;
typedef set<string> ss;

struct person{
	ss act;
};

struct activity;{
	ld x;
	ld y;
	ss act;
	int cap;
	int id;
};

person p[251];
activity a[251];


bool cmp(activity a,activity b){
	if(a.cap == b.cap){
		return a.cap < b.cap;
	}
}

int main(){
	int n,m;
	string temp;
	cin>>n;
	int k;
	f(i,0,n){
		cin>>k;
		k--;
		f(j,0,k){
			cin>>temp;
			p[i].act.insert(temp);
		}
	}
	cin>>m;
	ld x,y;
	f(i,0,m){
		cin>>temp;
		a[i].id=temp;
		cin>>x>>y;
		a[i].x=x;
		a[i].y=y;
		cin>>k;
		f(i,0,k){
			cin>>temp;
			a[i].act.insert(temp);
		}
	}
	f(i,0,m){
		ss::iterator it;
		f(j,0,n){
			for(it=a[i].act.begin();it!=a[i].act.end();++it){
				temp = (*it);
				if(p[j].act.find(temp) != p[j].act.end()){
					a[i].cap++;
				}
			}
		}
	}
	sort(a,a+m,cmp);
}