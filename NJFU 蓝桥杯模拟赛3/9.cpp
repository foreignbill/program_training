#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v;

bool check(int mid) {
	// o(N)
	int now = 1, nowpos = v[0];
	for(int i = 1; i < n; i ++) {
		if(nowpos + mid <= v[i]) {
			nowpos = v[i];
			now++;
		}
	}
	return now >= m;
}

int main () {
	ios::sync_with_stdio(false);
	cin >> n >> m; v.resize(n);
	for(auto &x : v) cin >> x;
	sort(v.begin(), v.end());
	int l = 0, r = v[n - 1] - v[0];
	int res = -1;
	// log 1e9 31
	while(l <= r) {
		int mid = (l + r) / 2;
		if(check(mid)) l = (res = mid) + 1;
		else r = mid - 1;
	}
	cout << res << endl;
	return 0;
}

// 假设有一方案 {A, B, C, D}
// 1 < A
// {1, B, C, D}