#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e6+5;
int dp[2][maxn];
int a[maxn],b[maxn],n,m;
int main(){
    while(~scanf("%d%d",&m,&n)){
        int t=1;
        for(int i=1;i<=n;i++){
            b[i]=dp[0][i]=dp[1][i]=0;
            scanf("%d",a+i);
        }
        for(int i=1;i<=m;i++){
            dp[t][i]=dp[t^1][i-1]+a[i];
            int Max=dp[t^1][i-1];
            for(int j=i+1;j<=n-m+i;j++){
                Max=max(Max,dp[t^1][j-1]);
                dp[t][j]=max(dp[t][j-1],Max)+a[j];
            }
            t=t^1;
        }
        printf("%d\n",*max_element(dp[t^1]+m,dp[t^1]+n+1));
    }
    return 0;
}
/*
dp[i][j] 表示前j个数字分成i组。
题目数据范围没给好，复杂度为O(n * m)，空间复杂度最大是 n * m 需要滚动。
*/