#include <algorithm>
#include <iostream>

using namespace std;

typedef struct num{
	long int circle_id;
	int value;
	int parent;
	int unique_id;
	int is_left;
	int right;
	int next_index;
}num;


typedef struct interval{
	int l;
	int r;
	int difference;
}interval;


bool comp(interval a,interval b){
	 return a.difference < b.difference;
}

void assign_parent(num *numbers,int n){
	int i=0;
	while(i<n){
		if(numbers[i].is_left==1){
			numbers[numbers[i].right].parent=numbers[i].parent;
		}
		i++;
	}
}

void initialize(num *numbers,int n){
	for(int i=0;i<n;i++){
		numbers[i].parent=-1;
		numbers[i].is_left=-1;
		numbers[i].value=i+1;
		numbers[i].circle_id=-1;
		numbers[i].next_index=i+1;
	}

}
int UNIQUE_ID;
int main(){
	int n;
	UNIQUE_ID=0;
	int m;
	cin>>n>>m;
	num *numbers;
	numbers=new num[n];
	initialize(numbers,n);
	interval MyInterval[m];
	int l,r;
	for(int i=0;i<m;i++){
		cin>>l>>r;
		MyInterval[i].l=l;
		MyInterval[i].r=r;
		MyInterval[i].difference=r-l;
	}
	sort(MyInterval,MyInterval+m,comp);
	long int circle_id=0;
	for(int i=0;i<m;i++){
		circle_id=0;
		l=MyInterval[i].l-1;
		r=MyInterval[i].r-1;
		int j=l;
		numbers[l].unique_id=UNIQUE_ID++;
		numbers[l].is_left=1;
		numbers[l].right=r;
		while(j<=r){
			if(numbers[j].circle_id==-1)
				j++;
			else {
				if(circle_id < numbers[j].circle_id+1){
					circle_id = numbers[j].circle_id+1;
				}
				numbers[j].parent=numbers[l].unique_id;
				j=numbers[j].next_index;
			}
		}
		j=l;
		while(j<=r){
			if(numbers[j].circle_id==-1){
				numbers[j].circle_id=circle_id;
				numbers[j].unique_id=numbers[l].unique_id;
				numbers[j].parent=numbers[l].parent;
			}
			j=numbers[j].next_index;
		}
		numbers[l].next_index=r+1;
	}
	int j=0;
	int count=0;
	assign_parent(numbers,n);
	for(int i=0;i<n-1;i++){
		if(numbers[i].circle_id==-1)
			continue;
		if((numbers[i+1].circle_id==numbers[i].circle_id-1 && numbers[i+1].parent==numbers[i].unique_id || numbers[i+1].circle_id==numbers[i].circle_id+1 && numbers[i+1].unique_id==numbers[i].parent)&&(numbers[i+1].circle_id!=-1))
			count++;
	}
	cout<<count<<endl;
	for(int i=0;i<n-1;i++){
		if(numbers[i].circle_id==-1)
			continue;
		if((numbers[i+1].circle_id==numbers[i].circle_id-1 && numbers[i+1].parent==numbers[i].unique_id || numbers[i+1].circle_id==numbers[i].circle_id+1 && numbers[i+1].unique_id==numbers[i].parent)&&(numbers[i+1].circle_id!=-1))
			cout<<(i+1)<<" "<<(i+2)<<endl;
	}


}