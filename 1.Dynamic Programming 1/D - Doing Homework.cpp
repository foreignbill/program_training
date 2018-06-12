#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = (1<<16) + 55;
const int maxm = 25;
struct node {
	int now,w,i;
	node(int _n=0,int _w=0):now(_n),w(_w){}
}dp[maxn];

string st[maxm];
int dead[maxm],cost[maxm];

void dfs(int now) {
	if(now == 0) return;
	int id = dp[now].i;
	dfs(now - (1<<dp[now].i));
	cout << st[id] << endl;
}

int main () {
	int T, n;
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> st[i] >> dead[i] >> cost[i];
		for(int s = 1; s < (1 << n); s ++) {
			dp[s].w = INT_MAX;
			for(int i = n - 1; i >= 0; i--) {
				if((s >> i) & 1) {
					int lst = s ^ (1 << i);
					int st = dp[lst].now + cost[i] - dead[i];
					st = max(st,0);
					if(st + dp[lst].w < dp[s].w) {
						dp[s].w = st + dp[lst].w;
						dp[s].now = dp[lst].now + cost[i];
						dp[s].i = i;
					}
				}
			}
		}
		cout << dp[(1<<n)-1].w << endl;
		dfs((1<<n)-1);
	}
	return 0;
}