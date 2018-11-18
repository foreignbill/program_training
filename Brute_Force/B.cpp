// 5 a
// 10 b
// a[15] = b
// 开始 2 最后 0
#include <bits/stdc++.h>

using namespace std;

int f[16];
// f[i] = 0 a
// f[i] = 1 b

bool check(int f[]) {
	int now = 2;
	for(int i = 1; i <= 15; i++) {
		if(f[i] == 0) now = now + now;
		else now--;
	}
	return now == 0;
}

int main () {
	for(int i = 1; i <= 5; i++) f[i] = 0;
	for(int i = 6; i <= 15; i++) f[i] = 1;
	int res = 0;
	do {
		if(f[15] == 1) {
			if(check(f)) res++;
		}
	} while(next_permutation(f+1, f+1+15));

	cout << res << '\n';
	// 000001111111111
	// 12345
	// 12354
	// 12435
	// 12453
	// ...
	// 54321
	// 
	// 11223
	// 11232
	// 11322
	// 12213
	// ...
	// 32211
	return 0;
}