#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 100;
const int mod = 1e9 + 7;
int n,m,k,T;
ll dp[1055];
ll cnt[20];

// 状态压缩DP， 求环...

int main () {
	//freopen("input.txt","r",stdin);
	for(scanf("%d",&T);T--;) {
		scanf("%d%d",&n,&m);
		memset(dp,0,sizeof dp);
		dp[0]=1;
		char opt[20];
		int u,v;
		for(;m--;) {
			scanf("%s%d%d",opt,&u,&v);
			u--;v--;
			if(opt[0]=='+') {
				for(int i=0;i<(1<<n);i++)
					if((i>>u&1)==0 && (i>>v&1)==0)
						dp[i|(1<<u)|(1<<v)] = (dp[i|(1<<u)|(1<<v)] + dp[i]) % mod;
			} else {
				for(int i=0;i<(1<<n);i++)
                    if((i>>u&1) && (i>>v&1))
                        dp[i]=(dp[i]-dp[i-(1<<u)-(1<<v)])%mod;
			}
			memset(cnt,0,sizeof cnt);
            for(int i=0;i<(1<<n);i++)
                if(__builtin_popcount(i)%2==0)
                    (cnt[__builtin_popcount(i)/2]+=dp[i])%=mod;
            for(int i=1;i<=(n>>1);i++)
                printf("%d%c",(cnt[i]%mod+mod)%mod," \n"[i==n>>1]);
		}
	}
	return 0;
}