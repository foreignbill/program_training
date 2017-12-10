#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool isprime(int n) {
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return true;
}

int main() {
	int n;
	cin >> n;
	puts(isprime(n) ? "YES" : "OK");
	return 0;
}