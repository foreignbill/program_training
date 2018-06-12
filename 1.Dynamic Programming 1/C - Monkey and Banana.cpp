#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e3 + 55;
struct node {
	int x,y,z;
	node(int _x=0,int _y=0,int _z=0):x(_x),y(_y),z(_z){}
}info[maxn];
int n,m,x,y,z;
int dp[maxn];

bool cmp (node A, node B) {
	if(A.x == B.x) return A.y > B.y;
	return A.x > B.x;
}

int main(){
	int cas = 1;
    while(~scanf("%d",&n), n) {
    	int top = 0;
    	for(int i=1;i<=n;i++) {
    		scanf("%d%d%d",&x,&y,&z);
    		info[++top] = node(x,y,z);
    		info[++top] = node(y,x,z);
    		info[++top] = node(x,z,y);
    		info[++top] = node(z,x,y);
    		info[++top] = node(y,z,x);
    		info[++top] = node(z,y,x);
    	}
    	memset(dp,0,sizeof dp);
    	sort(info+1,info+1+top,cmp);
    	int res = 0;
    	for(int i=1;i<=top;i++){
    		dp[i] = info[i].z;
    		for(int j=1;j<i;j++)
    			if(info[j].x > info[i].x && info[j].y > info[i].y)
    				dp[i] = max(dp[i],dp[j] + info[i].z);
    		res = max(res, dp[i]);
    	}
    	printf("Case %d: maximum height = %d\n",cas++,res);
    }
    return 0;
}