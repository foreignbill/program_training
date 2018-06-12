#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 1e5+55;
int pie[maxn][12];
int dp[maxn][12];
int n,Time,location,maxtime,mid,Lft,rht;;
int main () {
	while(scanf("%d",&n),n){
		memset(pie,0,sizeof(pie));
		memset(dp,0,sizeof(dp));
		maxtime=0;
		for(int i=0;i<n;i++){
			scanf("%d%d",&location,&Time);
			pie[Time][location+1]++;
			if(Time>maxtime)
				maxtime=Time;
		}
		for(int i=1;i<=11;i++)
			dp[maxtime][i]=pie[maxtime][i];
		for(int i=maxtime-1;i>=0;i--){
			for(int j=1;j<=11;j++){
				Lft=dp[i+1][j-1]+pie[i][j];
				mid=dp[i+1][j]+pie[i][j];
				rht=dp[i+1][j+1]+pie[i][j];
				dp[i][j]=max(Lft,mid);
				dp[i][j]=max(dp[i][j],rht);
			}
		}
		printf("%d\n",dp[0][6]);
	}
	return 0;
}