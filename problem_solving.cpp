//incomplete
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;
int n;
//returns index of greater than k.
int bin_search ( lli *A , int l , int r , int k ){
	if( l < r ){
		int mid = ( l + r ) / 2;
		if( A[mid]  > k ){
			return bin_search( A , l , mid - 1 , k );
		}
		else{
			return bin_search( A , mid + 1 , r , k );
		}
	}
	else {
		if ( A[l] > k )
			return l;
		else return l + 1;
	}
}

lli solve( int n , int k , lli *A ){
	sort( A , A + n );
	int count = 0;
	int *B = new lli[n];
	for ( int i = 0 ; i < n ; i++ )
		B[i] = A[i];
	int last = n ;
	int min_done = 100000;
	for ( int i = 0; i < n ; i++ ){
		if (  B[i] > 0 ){
			int current = A[i];
			while( true ){
				int next = bin_search( A , 0 , n - 1 , current + k );
				if( next == n ){
					break;
				}
				else{
					current = A[next];
					B[next] = 0;
				}
			}
			count++;
		}
		
	}
	return count;
}
int main(){
	ios_base::sync_with_stdio( false );
	int t;
	cin >> t;
	while( t-- ){
		int k;
		cin >> n >> k;
		lli *A = new lli[n];
		for( int i = 0; i < n; i++ ){
			cin >> A[i];
		}
		cout << solve ( n , k , A)<<endl;
	}
	return 0;
}
