#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 1e5 + 56;
int dp[maxn];
int n,a,b,vi,wi	;
int main () {
	int T;scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&a,&b);
		int w = b - a;
		memset(dp,63,sizeof dp);
		int mx = dp[0];
		dp[0] = 0;
		scanf("%d",&n);
		for(;n--;){
			scanf("%d%d",&vi,&wi);
			for(int j=wi;j<=w;j++)
				dp[j] = min(dp[j],dp[j-wi] + vi);
		}
		if(dp[w] == mx)
			puts("This is impossible.");
		else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[w]);
	}
	return 0;
}