#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 1e3 + 5;

struct node {
	int l,r,h;
	node(int _l=0,int _r=0,int _h=0):l(_l),r(_r),h(_h){}
	void read() {
		scanf("%d%d%d",&l,&r,&h);
	}
}info[maxn];
int n,m,x,y,mx;

int dp[maxn][2];

bool cmp(node A,node B) {
	return A.h > B.h;
}

int main () {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d%d",&n,&x,&y,&mx);
		for(int i=1;i<=n;i++)
			info[i].read();
		info[0]=node(x,x,y);
		sort(info+0,info+1+n,cmp);
		memset(dp,63,sizeof dp);
		int inf = dp[0][0];
		dp[0][1] = dp[0][0] = 0;
		for(int i=0;i<=n-1;i++) {
			bool flg1 = 1,flg2 = 1;
			for(int j=i+1;j<=n;j++) {
				//left
				if(info[j].l <= info[i].l && info[i].l <= info[j].r && info[i].h <= info[j].h+mx && flg1) {
					flg1 = 0;
					dp[j][0] = min(dp[j][0],dp[i][0]-info[j].h+info[i].h+info[i].l-info[j].l);
					dp[j][1] = min(dp[j][1],dp[i][0]-info[j].h+info[i].h+info[j].r-info[i].l);
				}

				//right
				if(info[j].l <= info[i].r && info[i].r <= info[j].r && info[i].h <= info[j].h+mx && flg2) {
					flg2 = 0;
					dp[j][0] = min(dp[j][0],dp[i][1]-info[j].h+info[i].h+info[i].r-info[j].l);
					dp[j][1] = min(dp[j][1],dp[i][1]-info[j].h+info[i].h+info[j].r-info[i].r);
				}
				if(!(flg1 || flg2)) break;
			}
		}
		int res = inf;
		for(int i=0;i<=n;i++){
			if(info[i].h > mx) continue;
			bool flg = 1;
			for(int j=i+1;j<=n;j++)
				if(info[j].l <= info[i].l && info[i].l <= info[j].r) {
					flg = 0;
					break;
				}
			if(flg)
				res = min(res,dp[i][0] + info[i].h);
			flg = 1;
			for(int j=i+1;j<=n;j++)
				if(info[j].l <= info[i].r && info[i].r <= info[j].r) {
					flg = 0;
					break;
				}
			if(flg)
				res = min(res,dp[i][1] + info[i].h);
		}
		printf("%d\n",res);
	}
	return 0;
}
/*
	dp[i][0..1] 0 from i left , 1 from i right

	dp[i][0] = max(dp[i][0],dp[j][0] + cost , dp[j][1] + cost);

	dp[i][1] = ...
*/