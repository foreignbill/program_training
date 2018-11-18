#include <bits/stdc++.h>

using namespace std;

// 38
int a[6][6];
int len[6] = {0, 3, 4, 5, 4, 3};
bool vis[20];

void dfs(int x, int y) {
	if(x == 6 && y == 1) {
		if(a[1][1] + a[2][1] + a[3][1] != 38) return;
		if(a[1][2] + a[2][2] + a[3][2] + a[4][1] != 38) return;
		if(a[1][3] + a[2][3] + a[3][3] + a[4][2] + a[5][1] != 38) return;
		if(a[2][4] + a[3][4] + a[4][3] + a[5][2] != 38) return;
		if(a[3][5] + a[4][4] + a[5][3] != 38) return;
		if(a[1][3] + a[2][4] + a[3][5] != 38) return;
		if(a[1][2] + a[2][3] + a[3][4] + a[4][4] != 38) return;
		if(a[1][1] + a[2][2] + a[3][3] + a[4][3] + a[5][3] != 38) return;
		if(a[2][1] + a[3][2] + a[4][2] + a[5][2] != 38) return;
		if(a[3][1] + a[4][1] + a[5][1] != 38) return;
		for(int i=1;i<=len[3];i++)
			cout << a[3][i] << endl;
		cout << "#" << endl;
		return;
	}
	if(y == len[x]) {
		int t = 38;
		for(int i = 1; i < len[x]; i++) t -= a[x][i];
		if(t > 0 && t < 20 && vis[t] == false) {
			vis[t] = true;
			a[x][y] = t;
			dfs(x + 1, 1);
			vis[t] = false;
		}
	} else {
		for(int i = 1; i < 20; i++)
			if(vis[i] == false) {
				vis[i] = true;
				a[x][y] = i;
				dfs(x, y + 1);
				vis[i] = false;
			}
	}
}

int main () {
	a[1][1] = 15; a[1][2] = 13; a[1][3] = 10;
	vis[10] = vis[13] = vis[15] = true;
	dfs(2, 1);
	return 0;
}