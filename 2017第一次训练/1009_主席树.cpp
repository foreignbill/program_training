#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int arr[maxn];
int Rank[maxn];

struct ChairTree {
#define lson tree[rt].lc,tree[rt1].lc,l,m
#define rson tree[rt].rc,tree[rt1].rc,m+1,r
    struct node {
        int lc, rc, w;
        node() {}
    } tree[maxn * 20];
    int root[maxn], cnt;
    void init() {
        root[0] = cnt = 0;
        memset(tree, 0, sizeof tree);
    }

    void add(int pos, int val, int &rt, int rt1, int l, int r) {
        tree[rt = ++cnt] = tree[rt1];
        tree[rt].w += val;
        if (l == r) return;
        int m = (l + r) / 2;
        if (pos <= m) add(pos, val, lson);
        else add(pos, val, rson);
    }

    int query(int k, int rt, int rt1, int l, int r) {
        if (l == r) return l;
        int lsize = tree[tree[rt1].lc].w - tree[tree[rt].lc].w;
        int m = (l + r) / 2;
        if (lsize >= k) return query(k, lson);
        else return query(k - lsize, rson);
    }
} T;

int main() {
    //freopen("in.txt","r",stdin);
    int cas, n, q, l, r, k;
    T.init();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        Rank[i] = arr[i];
    }
    sort(Rank + 1, Rank + 1 + n);
    int un = unique(Rank + 1, Rank + 1 + n) - (Rank + 1);
    for (int i = 1; i <= n; i++) {
        arr[i] = lower_bound(Rank + 1, Rank + 1 + un, arr[i]) - Rank;
    }
    for (int i = 1; i <= n; i++) {
        T.add(arr[i], 1, T.root[i], T.root[i - 1], 1, un);
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d%d", &l, &r, &k);
        int pos = T.query(r-l+2-k, T.root[l - 1], T.root[r], 1, un);
        printf("%d\n", Rank[pos]);
    }
    return 0;
}