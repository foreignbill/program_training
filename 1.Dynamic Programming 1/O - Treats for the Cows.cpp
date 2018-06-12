#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 2e3 + 55;

int p[maxn];
int dp[maxn][maxn];
int n;

int main() {
    while(~scanf("%d",&n)) {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++) {
            scanf("%d",&p[i]);
            dp[i][i]=p[i];
        }
        int ans=0;
        for(int i=n;i>=1;i--)
            for(int j=i;j<=n;j++) {
                dp[i][j]=max(dp[i + 1][j] + p[i] * (n + i - j), dp[i][j - 1] + p[j]*(n + i - j));
            }
        printf("%d\n",dp[1][n]);
    }
    return 0;
}
/*
dp[i][j] 表示 i 合并到 j的最大价值
可以由dp[i+1][j] 和 dp[i][j-1]推出
i+1 -> j 和 i -> j-1 长度 j - i,则 i -> j 第 n + i - j 次合并。
*/