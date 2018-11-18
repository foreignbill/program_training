#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
// 10000 ^ 3 = 1e12 > (2^31) - 1
// long long

ll s(ll n) {
	return n * n * n;
}

vector<int> solve(ll n) {
	vector<int> ret;
	// ret[];
	// 不定长数组
	// ret[0,1,2]
	// ret[0] ret[1]
	// ret.push_back(i)
	while(n != 0) {
		ret.push_back(n % 10);
		n = n / 10;
	}
	return ret;
}

bool compare(vector<int> r1, vector<int> r2) {
	int len1 = r1.size();
	int len2 = r2.size();
	int len = min(len1, len2);
	for(int i = 0; i < len; i++)
		if(r1[i] != r2[i]) return false;
	return true;
}

ll p10[] = {1,10,100,1000,10000,100000};

int main () {
	for(int i = 1; i <= 10000; i++) {
		// auto r1 = solve(i);// 4
		// auto r2 = solve(s(i));// 4 6
		// bool ok = compare(r1, r2);
		// if(ok) cout << i << endl;
		if(i == s(i) % p10[ (int)(log(i)/log(10))+1 ]) cout << i << endl;
	}
	return 0;
}