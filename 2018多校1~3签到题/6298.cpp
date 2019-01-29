#include <cstdio>

using namespace std;

/*
1 = 1 / a + 1 / b + 1 / c
a b c
-------
3 3 3
2 4 4
2 3 6
*/

int main () {
    int T,n;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        long long res=-1;
        if(n%3==0) res = 1ll * n * n * n / 27;
        else if(n%4==0) res = 1ll * n * n * n / 32;
        printf("%lld\n",res);
    }
    return 0;
}
