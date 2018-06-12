#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int maxm = 20 + 5;
const int maxd = 1600 + 10;
const int maxn = 300 + 5;
const int base = 805;

int f[maxn][maxm][maxd];//i choose j delta = k max;
bool p[maxn][maxm][maxd];
int P[maxn],D[maxn], n, m;

int ra,rb;
vector<int> res;
int dep;
inline void dfs(int x,int y,int k) {
    if(x == 0 && y == 0) 
        return;
    if(p[x][y][k]) dfs(x-1,y-1,k-P[x]+D[x]);
    else dfs(x-1,y,k);
    if(p[x][y][k]) {
        res.push_back(x);
        ra += P[x];
        rb += D[x];
    }
}

int main () {
    freopen("input.txt","r",stdin);
    int cas = 1;
    while(scanf("%d%d",&n,&m),n || m) {
        for(int i=1;i<=n;i++)
            scanf("%d%d",&P[i],&D[i]);
        //memset(f,-1,sizeof f);
        //memset(p,0,sizeof p);
        int md = base - m * 20;
        int mp = base + m * 20;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                for(int k=md;k<=mp;k++)
                    f[i][j][k] = -1;
        f[0][0][0 + base] = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=m;j++)
                for(int k=md;k<=mp;k++)
                    if(f[i][j][k] != -1) {
                        if(j!=m && md<=k + P[i+1] - D[i + 1] && k + P[i+1] - D[i + 1] <= mp)
                            if(f[i+1][j+1][k + P[i+1] - D[i + 1]] == -1 || (f[i+1][j+1][k + P[i+1] - D[i + 1]] < f[i][j][k] + P[i+1] + D[i+1])) {
                                f[i+1][j+1][k + P[i+1] - D[i + 1]] = f[i][j][k] + P[i+1] + D[i+1];
                                p[i+1][j+1][k + P[i+1] - D[i + 1]] = true;
                                //cout << i << " " << j << " " << k+ P[i+1] - D[i + 1] << endl;
                            }
                            //upd(f[i+1][j+1][k + P[i+1] - D[i + 1]], f[i][j][k] + P[i+1] + D[i+1]);
                        if(f[i+1][j][k] < f[i][j][k]){
                            f[i+1][j][k] = f[i][j][k];
                            p[i+1][j][k] = 0;
                        }
                        //upd(f[i+1][j][k],f[i][j][k]);
                    }
        }
        int dx = base,dy = base;
        ra = rb = 0;
        while(f[n][m][dx] == -1 && f[n][m][dy] == -1)
            dx--,dy++;
        res.clear();
        if(f[n][m][dx] == -1) {
            dfs(n,m,dy);
        } else if(f[n][m][dy] == -1) {
            dfs(n,m,dx);
        } else if(f[n][m][dx] > f[n][m][dy]) {
            dfs(n,m,dx);
        } else {
            dfs(n,m,dy);
        }
        printf("Jury #%d\n",cas++);
        printf("Best jury has value %d for prosecution and value %d for defence:\n",ra,rb);
        for(int i=0;i<(int)res.size();i++)
            printf(" %d",res[i]);
        puts("");
    }
    return 0;
}

// f[i][j][k] = f[i-1][j-1][k-delta] + sum | f[i-1][j][k]