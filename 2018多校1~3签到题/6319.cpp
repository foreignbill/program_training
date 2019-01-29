#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e7 + 555;
ll a[maxn];
int T,n,m,k,p,q,r,mod;
deque<int> Q;

// 从后往前逆序贪心搞

int main () {
    //freopen("input.txt","r",stdin);
    for(scanf("%d",&T);T--;) {
        scanf("%d%d%d%d%d%d%d",&n,&m,&k,&p,&q,&r,&mod);
        for(int i=1;i<=k;i++)
            scanf("%lld",&a[i]);
        for(int i=k+1;i<=n;i++)
            a[i] = (1ll * p * a[i-1] % mod + 1ll * q * i % mod + r) % mod;
        while(!Q.empty()) Q.pop_back();
        Q.push_front(n);
        for(int i=n-1;i>=n-m+1;i--){
            while(!Q.empty() && a[Q.front()] <= a[i]) Q.pop_front();
            Q.push_front(i);
        }
        ll ra = a[Q.back()] ^ (n - m + 1);
        ll rb = Q.size() ^ (n - m + 1);
        for(int i=n-m,j=n-1;i>=1;i--,j--) {
            while(!Q.empty() && Q.back() >= j+1) Q.pop_back();
            while(!Q.empty() && a[Q.front()] <= a[i]) Q.pop_front();
            Q.push_front(i);
            ra += a[Q.back()] ^ i;
            rb += Q.size() ^ i;
        }
        printf("%lld %lld\n",ra,rb);
    }
    return 0;
}