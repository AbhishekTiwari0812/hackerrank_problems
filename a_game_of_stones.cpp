#include <iostream>
using namespace std;

bool solve( int n ){
	if ( n == 0 || n == 1 ){
		return false;
	}
	else if ( n < 0 ){
		return true;
	}
	bool a;
	bool b; 
	bool c;
	a = !( solve( n - 2 ) );
	b = !( solve( n - 3 ) );
	c = !( solve( n - 5 ) );
	return a || b || c;
} 

int main(){
	int t;
	cin >> t;
	while( t-- ){
		int n;
		cin >> n;
		bool flag = solve( n );
		if( flag )
			cout << "FIRST" << endl;
		else cout << "SECOND" << endl;
	}
	return 0;
}