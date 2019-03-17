#include <bits/stdc++.h>

using namespace std;

int g[6][6], res = 0;

bool vis[10];

const int dx[] = {0,0,1,-1,1,1,-1,-1};
const int dy[] = {1,-1,0,0,1,-1,1,-1};

bool check() {
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <=4; j++) {
            if( (i == 1 && j == 1) || (i == 3 && j == 4) ) continue;
            bool ok = true;
            for(int ii = 0; ii < 8; ii ++) {
                int nx = i + dx[ii];
                int ny = j + dy[ii];
                if(g[nx][ny] == -1) continue;
                if(abs(g[nx][ny] - g[i][j]) == 1) return false;
            }
        }
    }
    return true;
}

void dfs(int x, int y) {
    if(x == 3 && y == 4) {
        if(check()) res ++;
    }
    if((x == 1 && y == 4) || (x == 2 && y == 4)) {
        for(int i = 0; i < 10; i++) {
            if(vis[i]) continue;
            vis[i] = true;
            g[x][y] = i;
            dfs(x + 1, 1);
            g[x][y] = -1;
            vis[i] = false;
        }
    } else {
        for(int i = 0; i < 10; i++) {
            if(vis[i]) continue;
            vis[i] = true;
            g[x][y] = i;
            dfs(x, y + 1);
            g[x][y] = -1;
            vis[i] = false;
        }
    }
}

int main () {
    memset(g, -1, sizeof g);
    memset(vis, 0, sizeof vis);
    dfs(1, 2);
    cout << res << endl;
    return 0;
}

/*
+--+--+--+--+
|  | 1| 2| 3|
+--+--+--+--+
| 4| 5| 6| 7|
+--+--+--+--+
| 8| 9|10|  |
+--+--+--+--+
*/