#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct point{
    int x;
    int y;
}point;
point A[8];

int collides(point &a,point &b){
	if(a.x==b.x)
		return 1;
	else if(a.y==b.y)
		return 1;
	else if(abs(a.x-b.x)==abs(a.y-b.y))
		return 1;

	else return 0;			//doesn't collide
}

int check_val(int current){
	for(int i=current-1;i>=0;i--){	
		//cout<<"The points :("<<A[i].x<<","<<A[i].y<<") ("<<A[current].x<<","<<A[current].y<<")\n";
		//cout<<"collides:"<<collides(A[i],A[current])<<endl;
		if(collides(A[i],A[current]))
			return 0;	//not valid
	}
	return 1;			//valid
}

int main() {
    string a;
    int i;
    int flag=0;
    for(i=0;i<8;i++){
    	cin>>a;
        for(int j=0;j<8;j++)
            if(a[j]=='*'){
               A[i].x=i;
               A[i].y=j;
            }
        if(!check_val(i))
        	break;
            }

    if(i==8)
    	cout<<"valid"<<endl;
    else cout<<"invalid"<<endl;
    return 0;
}
