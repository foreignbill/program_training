#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn=2005;
const ll inf=1e15;
int n;
int a[maxn],b[maxn];
ll dp[maxn][maxn];
void solve() {
	for(int i=1;i<=n;i++) {
		ll mn=dp[i-1][1];
		for(int j=1;j<=n;j++) {
			mn=min(mn,dp[i-1][j]);
			dp[i][j]=abs(a[i]-b[j])+mn;
		}
	}
	ll ans=dp[n][1];
	for(int i=1;i<=n;i++)
		ans=min(ans,dp[n][i]);
	printf("%lld\n",ans);
}
int main () {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		b[i] = a[i];
	}
	sort(b+1,b+1+n);
	solve();
	return 0;
}
/*
dp[i][j]=abs(j-w[i])+min(dp[i-1][k]);(k<=j)
j \in a{};
*/