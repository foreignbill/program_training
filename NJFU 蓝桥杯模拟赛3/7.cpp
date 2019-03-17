#include <bits/stdc++.h>

using namespace std;

int n, k, res = 0;

void dfs(int left, int k, int pre) {
	if(k == 0) {
		if(left == 0) res++;
		return;
	}
	if(k * pre > left) return;
	for(int i = pre; i <= left; i++) {
		dfs(left - i, k - 1, i);
	}
}

int main() {
	cin >> n >> k;
	dfs(n, k, 1);
	cout << res << endl;
	return 0;
}