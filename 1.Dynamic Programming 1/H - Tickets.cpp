#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 5e3 + 55;
int dp[maxn][2];
int a[maxn],b[maxn],n;

int main () {
    int T;scanf("%d",&T);
    for(;T--;) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=2;i<=n;i++)
            scanf("%d",&b[i]);
        memset(dp,63,sizeof dp);
        dp[1][0] = dp[1][1] = a[1];
        for(int i=2;i<=n;i++) {
            dp[i][1] = dp[i-1][0] - a[i - 1] + b[i];
            dp[i][0] = min(dp[i-1][0],dp[i-1][1]) + a[i];
        }
        int ans = min(dp[n][0],dp[n][1]);
        int h = 8,m = 0,s = 0;
        h += ans / 3600;
        m += ans % 3600 / 60;
        s += ans % 60;
        if(h >= 12) {
            printf("%02d:%02d:%02d pm\n",h%12,m,s);
        } else {
            printf("%02d:%02d:%02d am\n",h,m,s);
        }
    }
    return 0;
}
/*
    dp[i][0..1] 0只选自己 1选两个一起

    简化版
    dp[i] = min(dp[i-1]+a[i],dp[i-2]+b[i])
*/