#include <bits/stdc++.h>

using namespace std;

int main () {
	// b/a * c/d = (b*10 + c) / (a * 10 + d)
	int res = 0;
	for(int a = 1; a < 10; a++)
		for(int b = 1; b < 10; b++)
			for(int c = 1; c < 10; c++)
				for(int d = 1; d < 10; d++) {
					int e = b * 10 + c;
					int f = a * 10 + d;
					int g = b * c;
					int h = a * d;
					if(e * h == g * f) res ++;
				}
	cout << res - 9 * 9<< endl;
	return 0;
}