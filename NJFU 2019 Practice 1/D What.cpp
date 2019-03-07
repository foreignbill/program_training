#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 555;
int dist[maxn][4][3];

int swap(int now, int s, int t) {
    int b[7];
    for(int i = 1; i <= 5; i++) {
        b[i] = now % 10;
        now /= 10;
    }
    swap(b[s], b[t]);
    int ret = 0;
    for(int i = 5; i >= 1; i--) {
        ret = ret * 10 + b[i];
    }
    return ret;
}

int add(int now, int s) {
    int b[7];
    for(int i = 1; i <= 5; i++) {
        b[i] = now % 10;
        now /= 10;
    }
    b[s] = (b[s] + 1) % 10;
    int ret = 0;
    for(int i = 5; i >= 1; i--) {
        ret = ret * 10 + b[i];
    }
    return ret;
}

int mul(int now, int s) {
    int b[7];
    for(int i = 1; i <= 5; i++) {
        b[i] = now % 10;
        now /= 10;
    }
    b[s] = (b[s] * 2) % 10;
    int ret = 0;
    for(int i = 5; i >= 1; i--) {
        ret = ret * 10 + b[i];
    }
    return ret;
}

int main () {
    memset(dist, -1, sizeof dist);
    dist[12345][3][2] = 0;
    queue<pair<int, pair<int, int>> > Q;
    Q.push({12345, {3, 2}});
    while(Q.size()) {       
        auto top = Q.front(); Q.pop();
        int now = top.first;
        int a1 = top.second.first;
        int a2 = top.second.second;
        for(int i = 1; i <= 4; i++) {
            int tp = swap(now, i, i + 1);
            if(dist[tp][a1][a2] == -1) {
                dist[tp][a1][a2] = dist[now][a1][a2] + 1;
                Q.push({tp, {a1, a2}});
            }
        }

        for(int i = 1; i <= 5 && a1 >= 1; i++) {
            int tp = add(now, i);
            if(dist[tp][a1 - 1][a2] == -1) {
                dist[tp][a1 - 1][a2] = dist[now][a1][a2] + 1;
                Q.push({tp, {a1 - 1, a2}});
            }
        }

        for(int i = 1; i <= 5 && a2 >= 1; i++) {
            int tp = mul(now, i);
            if(dist[tp][a1][a2 - 1] == -1) {
                dist[tp][a1][a2 - 1] = dist[now][a1][a2] + 1;
                Q.push({tp, {a1, a2 - 1}});
            }
        }
    }
    ios::sync_with_stdio(false);
    int x;
    while(cin >> x) {
        int res = INT_MAX;
        for(int i = 0; i <= 3; i++)
            for(int j = 0; j <= 2; j++)
                if(dist[x][i][j] != -1)
                    res = min(res, dist[x][i][j]);
        if(res == INT_MAX) res = -1;
        cout << res << "\n";
    }
    return 0;
}