#include <bits/stdc++.h>

using namespace std;

int main () {
	double res = 0;
	for(int i=1;;i++) {
		res += 1.0 / i;
		if(res > 15.0) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}