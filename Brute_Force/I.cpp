#include <bits/stdc++.h>

using namespace std;

int a[5][5];
// 34
bool vis[17];
int res = 0;

void dfs(int x, int y) {
	if(x == 5 && y == 1) {
		if(a[1][1] + a[2][2] + a[3][3] + a[4][4] != 34) return;
		if(a[1][4] + a[2][3] + a[3][2] + a[4][1] != 34) return;
		res ++;
		return;
	}
	if(y == 4) {
		int t = 34 - a[x][1] - a[x][2] - a[x][3];
		if(t > 0 && t < 17 && vis[t] == false) {
			a[x][y] = t;
			vis[t] = true;
			dfs(x + 1, 1);
			vis[t] = false;
		}
	} else if(x == 4) {
		int t = 34 - a[1][y] - a[2][y] - a[3][y];
		if(t > 0 && t < 17 && vis[t] == false) {
			a[x][y] = t;
			vis[t] = true;
			dfs(x, y + 1);
			vis[t] = false;
		}
	} else {
		for(int i=2;i<=16;i++)
			if(vis[i] == false) {
				a[x][y] = i;
				vis[i] = true;
				dfs(x, y + 1);
				vis[i] = false;
			}
	}
}

int main () {
	a[1][1] = 1;
	memset(vis, 0, sizeof vis);
	// vis[x] == false x 没有用过， 还可以放
	// vis[x] == true  x 放过了， 不能再放
	vis[1] = true;
	dfs(1, 2);
	cout << res << endl;
	return 0;
}