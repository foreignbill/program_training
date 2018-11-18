#include <bits/stdc++.h>

using namespace std;

double f(double n) {
	// f(n) = n / (n + f(n + 1));
	if(n > 10000) return 0;
	return n / (n + f(n + 1));
}

int main () {
	cout << f(1) << "\n";
	return 0;
}
