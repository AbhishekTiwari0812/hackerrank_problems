#include <cmath>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define INF 1<<30
#define SPEED 5


using namespace std;

typedef struct point{
    double x;
    double y;
}point;
double d(point &a,point &b){
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
double *DP;
point a;
point b;
point *cannons;
int cannon_count;
bool comp(point &p,point &q){
    if(d(p,a) >= d(q,a))
        return true;
    return false;
}

double cal_cost(){

    double min_cost=INF;
    for(int i=0;i<cannon_count;i++){

    }  
}


int main() {
    cin>>a.x>>a.y;
    cin>>b.x>>b.y;
    cin>>cannon_count;
    DP=(double *)malloc(sizeof(double)*cannon_count);
    cannons=(point *)malloc(sizeof(point)*cannon_count);
    double p;   //temp
    for(int i=0;i<cannon_count;i++){
        DP[i]=INF;
        cin>>p;
        cannons[i]->x=p;
        cin>>p;
        cannons[i]->y=p;
    }
    sort(cannons,cannons+cannon_count,comp);
    printf("%.3f\n",cal_cost());
    return 0;
}
