#include <bits/stdc++.h>
#define PI 3.14159265359
#define f(i,a,b) for(int i=(a), __=(b);i<__;++i)
using namespace std;
typedef long double ld;

struct place{
  string id;
  set<string> poe;
  ld x;
  ld y;
  int popularity;
  string next_destination;
  ld distance;
};

place d[251];

struct person{
  int id;
  set<string> interest;
};

int n,c;  //number of people, count of places 
person p[250];

bool cmp(place &a,place &b){
  return a.popularity < b.popularity;
}

ld degree2radians(ld degree){
  return (PI*degree)/180.0;
}

ld dist(place &a,place &b){
    ld EARTH_RADIUS = 6371;//in km
    ld point1_lat_in_radians  = degree2radians( a.x );
    ld point2_lat_in_radians  = degree2radians( b.x );
    ld point1_long_in_radians  = degree2radians( a.y );
    ld point2_long_in_radians  = degree2radians( b.y );

    return acos( sin( point1_lat_in_radians ) * sin( point2_lat_in_radians ) +
                 cos( point1_lat_in_radians ) * cos( point2_lat_in_radians ) *
                 cos( point2_long_in_radians - point1_long_in_radians) ) * EARTH_RADIUS;
}

void closest_pair(vector<place> v){
  string p1,p2;
  ld min_dist=INT_MAX;
  ld temp_dist;
  f(i,0,v.size()-1){
    f(j,i+1,v.size()){
      temp_dist = dist(v[i],v[j]);
      if(temp_dist < min_dist){
	min_dist=temp_dist;
	p1 = v[i].id;
	p2 = v[j].id;
      }
    }
  }
  cout<<p1<<' '<<p2<<endl;
}

int main(){
  int n;
  cin>>n;
  int m;
  string temp;
  f(i,0,n){
    cin>>m;
    p[i].id=i;
    f(j,0,m){
      cin>>temp;
      p[i].interest.insert(temp);
    }
  }
  cin>>c;
  ld x,y;
  f(i,0,c){
    cin>>temp;
    d[i].id=temp;
    d[i].popularity=0;
    cin>>x>>y;
    d[i].x=x;
    d[i].y=y;
    cin>>m;
    f(i,0,m){
      cin>>temp;
      d[i].poe.insert(temp);
    }
  }
  f(i,0,c){
    f(j,0,n){
      set<string>::iterator it;
      for(it=p[j].interest.begin();it!=p[j].interest.end();++it){
	if(d[i].poe.find( (*it)) != d[i].poe.end()){
	  d[i].popularity++;
	  break;
	}
      }
    }
  }
  sort(d,d+c,cmp);
  vector<place> top_places;
  int biggest = d[c-1].popularity;
  top_places.push_back(d[c-1]);
  for(int i=c-2;i>=0;--i){
    if(d[i].popularity < biggest){
      if(i==c-2){
	top_places.push_back(d[i]);
      }
      break;
    }
    else top_places.push_back(d[i]);
  }
  closest_pair(top_places);
  return 0;
}
