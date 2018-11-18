#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll res = 0;

void dfs(int n, int now) { // n -> 当前选择的牌的点数， now -> 当前总共选得牌数
	if(n == 14) {
		if(now == 13) res++;
		return;
	}
	if(now == 13) {
		res ++;
		return;
	}
	if(now > 13) {
		return;
	}
	for(int i = 0; i < 5; i++)
		dfs(n + 1, now + i);
}

int main () {
	// 52 xuan 13
	// 忽略花色
	dfs(1, 0);
	cout << res << endl;
	return 0;
}