#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 1e3 + 555;
typedef long long ll;
struct node {
    int x, y, id;
    node(int _x=0, int _y=0):x(_x), y(_y){}
    void read(int i) {
        scanf("%d%d", &x, &y);
        id = i;
    }
}info[maxn*3];

bool cmp(node A, node B) {
    if(A.x == B.x) return A.y < B.y;
    return A.x < B.x;
}

/*
随便按x优先排，y其次
不存在三点共线
*/

int main () {
    int T,n;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 1;i <= n * 3; i++)
            info[i].read(i);
        sort(info + 1, info + 1 + 3 * n, cmp);
        for(int i = 1; i <= 3 * n; i += 3) {
            printf("%d %d %d\n",info[i].id,info[i+1].id,info[i+2].id);
        }
    }
    return 0;
}