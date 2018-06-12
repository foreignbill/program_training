#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn = 1e3 + 5;
int dp[maxn][maxn],n;
char s[maxn][maxn];

int main() {
    while(scanf("%d",&n),n) {
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<n; i++) {
            scanf("%s",s[i]);
        }
		for(int i=0; i<n; i++) dp[0][i] = 1, dp[i][n-1] = 1;
        int ans = 1;
        for(int i=1; i<n; i++) {
            for(int j=n-2; j>=0; j--) {
                int x = i-1, y = j+1;
                int cnt = 1;
                while(x>=0 && x<n && y>=0 && y<n && s[x][j] == s[i][y]) {
                    cnt++;
                    x--;
                    y++;
                }
                if(cnt > dp[i-1][j+1]) dp[i][j] = dp[i-1][j+1]+1;
                else dp[i][j] = cnt;
                ans = max(dp[i][j], ans);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
cnt = (i,j) 为左下角，相同的最长长度。
dp[i][j] = dp[i-1][j+1] + 1 | cnt > dp[i-1][j+1]
dp[i][j] = cnt | cnt <= dp[i-1][j+1]
*/