#include <bits/stdc++.h>

using namespace std;

int main () {
	// 23x + 19y = 823
	// x < y
	// x > 0
	// y > 0
	for(int x = 1; ;x++) {
		if( ( 823 - 23 * x ) % 19 != 0) continue;
		int y = ( 823 - 23 * x ) / 19;
		if(x < y) {
			cout << x << " " << y << endl;
			return 0;
		}
	}
	return 0;
}