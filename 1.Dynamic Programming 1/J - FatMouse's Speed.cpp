#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 1e3 + 5;

struct node {
	int a,b,id;
}a[maxn];

bool cmp(node A,node B) {
	return A.a == B.a ? A.b >B.b : A.a < B.a;
}

int dp[maxn];
int pre[maxn];

void dfs(int id) {
	if(id == 0) return;
	dfs(pre[id]);
	printf("%d\n",a[id].id);
}

int main () {
	//freopen("input.txt","r",stdin);
	int n = 1;
	while(~scanf("%d%d",&a[n].a,&a[n].b)) {
		a[n].id = n; n++;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) {
		dp[i] = 0;
		pre[i] = 0;
		int mx = 0, id = 0;
		for(int j=1;j<i;j++)
			if(a[j].a < a[i].a && a[j].b > a[i].b && mx < dp[j]) {
				mx = dp[j];
				id = j;
			}
		dp[i] = mx + 1;
		pre[i] = id;
	}
	int mx = 0, id = 0;
	for(int i=1;i<=n;i++)
		if(mx < dp[i]) {
			mx = dp[i];
			id = i;
		}
	printf("%d\n",mx);
	dfs(id);
	return 0;
}
/*
	LIS 记录路径
*/