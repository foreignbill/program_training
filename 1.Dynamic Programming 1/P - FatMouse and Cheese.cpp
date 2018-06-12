#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
const int maxn = 1e2 + 55;
int dp[maxn][maxn];
int a[maxn][maxn];
int n,k;

int dfs(int x,int y) {
	if(dp[x][y]!= -1) return dp[x][y];
	dp[x][y] = 0;
	for(int i=1;i<=k;i++)
		for(int j=0;j<4;j++) {
			int nx = x + dx[j] * i;
			int ny = y + dy[j] * i;
			if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
			if(a[nx][ny] > a[x][y])
				dp[x][y] = max(dp[x][y],dfs(nx,ny));
		}
	dp[x][y] += a[x][y];
	return dp[x][y];
}

int main () {
	while(scanf("%d%d",&n,&k),(n+1)||(k+1)) {
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) {
				scanf("%d",&a[i][j]);
				dp[i][j] = -1;
			}
		cout << dfs(1,1) << endl;
	}
	return 0;
}