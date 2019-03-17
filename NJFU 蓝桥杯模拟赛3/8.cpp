#include <bits/stdc++.h>

using namespace std;

struct node {
	int l, r;
};

node v[1005];
int n;

bool comp(node A, node B) {
	return A.r < B.r;
}

int main () {
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> v[i].l >> v[i].r;
	sort(v, v + n, comp);

	int current_end = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		// i 这个活动 是在所有剩下的里面是能最早结束的
		// i 这个活动现在可以安排
		if(current_end < v[i].l) {
			current_end = v[i].r;
			cnt ++;
		}
	}
	cout << cnt << "\n";
	return 0;
}

/*
	[l, r]
	dp[i][0..1] 0 不放， 1 表示放 必须以它作为当前最后一个的任务
	dp[i][0] = dp[i-1][0..1]
	dp[i][1] = Max{dp[j][1], dp[k][0]} + 1
*/