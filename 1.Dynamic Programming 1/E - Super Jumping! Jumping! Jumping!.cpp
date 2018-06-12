#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 1e3 + 55;

int n,top,a[maxn];
ll dp[maxn];

int main () {
	while(scanf("%d",&n),n) {
		for(int i=1;i<=n;i++) scanf("%d",a + i);
		ll res = 0;
		for(int i=1;i<=n;i++){
			dp[i] = a[i];
			for(int j=1;j<i;j++)
				if(a[j] < a[i])
					dp[i] = max(dp[i],dp[j] + a[i]);
			res = max(res,dp[i]);
		}
		cout << res << endl;
	}
	return 0;
}
/*
	LIS
*/