#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;



int count_val_pts(int &A,int &B){
	int max=A>B?A:B;
	int min=A<B?A:B;
	int size_1=(int)log2(max)+1;
	int size_2=(int)log2(min)+1;
	long long int count=1;
	int different_nums=0;
	int pow=2;
	

	// all size_1 -1 bits and size_2 -1 bits combination
	for(int i=1;i<=size_2-1;i++){
		different_nums=pow;
		if(i!=1)
			pow=pow<<1;
		count+=different_nums*(size_1-i);
	}

	cout<<"including Size_1 -1 and Size_2 -1 bits:"<<count<<endl;
	long int a_beg=(1<<(size_1-1));
	long int b_beg=(1<<(size_2-1));
	//all size_2 bit numbers, size_1 - 1 complements
	
	count+=(min-b_beg+1)*(size_1-size_2+1);
	cout<<"including size_1 -1 and size_2  bits:"<<count<<endl;
	//all size_1 bits and 0,1,2...size_2-1 bits
	long int a_prime=(1<<size_1)-1;
	int i=1;
	int count_zero=0;
	while(a_prime > max){
		a_prime=(a_prime>>i);
		a_prime=(a_prime<<i);
		i++;
		count_zero+=1;
	}
	////////*************************************/////////



	cout<<"including Size_1  and Size_2 -1 bits:"<<count<<endl;
	
	max_prime=(1<<(size_1+1))-1;
	max_prime=max_prime>>(size_1-size_2);
	max_prime=max_prime<<(size_1-size_2);
	long int min_prime=(1<<size_2);
	long int complementor=1<<(size_2+1);
	while(min_prime<=min){
		if(max_prime+(complementor-min_prime) <= max)
			count+=1;
		else break;
		min_prime+=1;
	}
	cout<<"including Size_1  and Size_2 bits:"<<count<<endl;
	return count;
}





int main() {
    int test;
    int x,y;
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>x>>y;
        cout<<count_val_pts(x,y)<<endl;
    }
    return 0;
}
