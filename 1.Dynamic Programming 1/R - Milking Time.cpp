#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 1e4 + 55;
int dp[maxn];
struct node {
    int s,e,v;
    node(int _s=0,int _e=0,int _v=0):s(_s),e(_e),v(_v){}
    void read() {
        scanf("%d%d%d",&s,&e,&v);
    }
}info[maxn];

int n,m,t;

bool cmp(node A,node B) {
    return A.s == B.s ? A.e < B.e : A.s < B.s;
}

int main () {
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=m;i++) {
        info[i].read();
        info[i].e += t;
    }
    sort(info+1,info+1+m,cmp);
    int res = 0;
    for(int i=1;i<=m;i++) {
        dp[i] = info[i].v;
        for(int j=1;j<i;j++)
            if(info[j].e <= info[i].s)
                dp[i] = max(dp[i],dp[j] + info[i].v);
        res = max(dp[i],res);
    }
    cout << res << endl;
    return 0;
}
/*
dp[i] = max{dp[j] + info[i].v} | j 之后 可以 做i
*/