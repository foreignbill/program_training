#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
char mp[55][55];
int vis[55][55];
int sx, sy, ex, ey;
vector<pair<int, int> > V[3];

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void dfs(int x, int y, int tag) {
	vis[x][y] = tag;
	V[tag].push_back(make_pair(x, y));
	for(int i = 0; i < 4; i ++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
		if(vis[nx][ny] != 0) continue;
		if(mp[nx][ny] == '1') continue;
		dfs(nx, ny, tag);
	}
}

int main () {
	scanf("%d", &n);
	scanf("%d%d", &sx, &sy);
	scanf("%d%d", &ex, &ey);
	for(int i = 1; i <= n; i++) {
		scanf("%s", mp[i] + 1);
	}
	dfs(sx, sy, 1);
	if(vis[ex][ey] == 1) {
		puts("0");
		return 0;
	}
	dfs(ex, ey, 2);
	ll cost = LONG_MAX;
	for(auto e1 : V[1])
		for(auto e2 : V[2]) {
			cost = min(cost, 1ll * (e1.first - e2.first) * (e1.first - e2.first) + 1ll * ((e1.second - e2.second) * (e1.second - e2.second)));
		}
	cout << cost << endl;
	return 0;
}