//modify this to use array instead of set to solve!
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

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef vector<lli> vi;
typedef vector<lli> vl;
typedef vector<string> vs;
struct xored{
	lli x;
	lli i;
	lli j;
};


lli helper[4];
lli quad(lli x,lli y,lli z,lli w){
	cout<<"("<<x<<","<<y<<","<<z<<","<<w<<")"<<endl;
	helper[0]=x;
	helper[1]=y;
	helper[2]=z;
	helper[3]=w;
	sort(helper,helper+4);
	return helper[0]+3001*helper[1]+90000009*helper[2]+8100000000079*helper[3];
}

bool cmp(xored &a, xored &b){
	return a.x < b.x;
}

lli size1,size2;

lli lin_search(xored *a,lli start,lli k){
	if(start == -1)
		start++;
	while(a[start].x < k){
		start++;
		if(start == size2)
			return -1;
	}
	if(a[start].x > k)
		return -1;
	else return start;
}

lli bin_search(xored *a,lli l,lli r,lli k){
	if(l <= r){
		lli mid=(l+r)/2;
		if(a[mid].x >= k){
			return bin_search(a,l,mid-1,k);
		}
		else if(a[mid].x < k){
			return bin_search(a,mid+1,r,k);
		}
	}
	return lin_search(a,r,k);
}


lli solve(xored *A,xored *B,lli size1,lli size2){
	sort(A,A+size1,cmp);
	sort(B,B+size2,cmp);
	set<long> s;
	for(lli i=0;i<size1;i++){
		lli k=bin_search(B,0,size2-1,A[i].x);
		if(k!=-1){
			while(B[k].x==A[i].x){
				//momdify here.
				s.insert(quad(A[i].i,A[i].j,B[k].i,B[k].j));
				k++;
			}
		}
	}
	return s.size();

}
lli count_total(lli a,lli b,lli c,lli d){
	helper[0]=a;
	helper[1]=b;
	helper[2]=c;
	helper[3]=d;
	sort(helper,helper+4);
	lli sum=0;
	//modify here last
	for(lli i=1;i<=helper[0];i++){
		lli x1 = (1+helper[3])*(1+helper[2])*(helper[1]-i+1);
		lli x2 =  (1+helper[3])*( ((helper[1]*(helper[1]+1))/2)-((i*(i-1))/2));
		lli x3 = ((helper[2]*(helper[2]+1)) /2)*(helper[1]-i+1);
		lli x4 = (helper[1] * (helper[1]+1)*(2*helper[1] +1)-((i-1)*i*(2*i-1)))/6;
		x4-= ((helper[1]*(helper[1]+1) )/2 )- ((i*(i-1))/2);
		sum += x1-x2-x3+(x4/2);


	}
	//cout<<sum<<endl;
	return sum;
}

int main(){
	lli a,b,c,d;
	cin>>a>>b>>c>>d;
	size1=a*c;
	size2=b*d;
	xored *A=new xored[a*c];
	xored *B=new xored[b*d];
	lli k=0;
	for(lli i=1;i<=a;i++){
		for(lli j=1;j<=c;j++){
			A[k].i=i;
			A[k].j=j;
			A[k].x=i^j;
			k++;
		}
	}
	k=0;
	for(lli i=1;i<=b;i++){
		for(lli j=1;j<=d;j++){
			B[k].i=i;
			B[k].j=j;
			B[k].x=i^j;
			k++;
		}
	}
	lli invalid=solve(A,B,a*c,b*d);
	lli total=count_total(a,b,c,d);
	cout<<(total - invalid)<<endl;
	return 0;
}

