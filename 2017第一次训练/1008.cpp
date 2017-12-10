#include <bits/stdc++.h>
using namespace std;
#define ll long long
//head
/*
这是一道思路题，由本题的定义可知，这些车站被分成了若干个块，我们可以连接其中任意两块，是得价值最大
假设，其中两块的价值分别为 a,b，那么连接后的价值为(a+b)^2，由因为 a^2+b^2 <=(a+b)^2
所以我们只需要找到两个最大的块，将它们连在一起，必定满足最大的性质
 */
const int maxn = 100000 + 100;
int n;
int vis[maxn];
vector<int> b;
int a[maxn];

void dfs(int idx) {
    int cnt = 1;
    int nxt = a[idx];
    vis[idx] = true;
    while (nxt != idx) {
        vis[nxt] = true;
        cnt++;
        nxt = a[nxt];
    }
    b.push_back(cnt);
}
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        dfs(i);
    }
    sort(b.begin(), b.end(), cmp);
    long long ans = 0;
    if (b.size() == 1) ans = (ll)b[0] * b[0];
    else if (b.size() == 2) {
        ans = (ll)(b[0] + b[1]) * (b[0] + b[1]);
    }
    else {
        ans += (ll)(b[0] + b[1]) * (b[0] + b[1]);

        for (int i = 2; i < b.size(); i++) ans += (ll)b[i] * b[i];
    }
    cout << ans << endl;
    return 0;
}