#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int calc(ll x) {
    int ret = 0;
    while(x > 0) {
        if(x % 10 == 1) ret++;
        x /= 10;
    }
    return ret;
}

int main () {
    ll s = 0;
    int cnt = 0;
    for(int i = 1; i <= 1111111110; i++) {
        s += calc(i);
        if(s == i) {
            cout << ++ cnt << " " << i << endl;
        }
    }
    return 0;
}