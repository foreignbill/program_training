#include <cstdio>

const int maxn = 4e5 + 555;

struct edge{
    int nxt, to;
    edge(int _nxt = 0, int _to = 0): nxt(_nxt), to(_to) {}
};

int head[maxn], tail[maxn];
edge e[maxn];
int n, q, x, tot, cnt, rk[maxn], pos[maxn], sz[maxn];

void dfs(int id) {
    cnt++;
    pos[id] = cnt;
    rk[cnt] = id;
    sz[id] = 1;
    for(int k = head[id]; k; k = e[k].nxt) {
        dfs(e[k].to);
        sz[id] += sz[e[k].to];
    }
}

int main () {
    tot = 0;
    scanf("%d%d", &n, &q);
    for(int i = 2; i <= n; i++) {
        scanf("%d", &x);
        if(head[x] == 0) {
            e[++tot] = edge(head[x], i);
            head[x] = tot;
            tail[x] = tot;
        } else {
            e[tail[x]].nxt = ++tot;
            e[tot] = edge(0, i);
            tail[x] = tot;
        }
    }
    cnt = 0;
    dfs(1);
    int s, t;
    for(;q--;) {
        scanf("%d%d", &s, &t);
        if(t > sz[s]) {
            puts("-1");
        } else {
            printf("%d\n", rk[pos[s] + t - 1]);
        }
    }
}