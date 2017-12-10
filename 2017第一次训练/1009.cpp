#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
int a[maxn], b[maxn];
int main() {
	int n, l, r, k, t;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &l, &r, &k);
		for (int i = l; i <= r; i++)
			b[i - l + 1] = a[i];
		sort(b + 1, b + r - l + 2);
		printf("%d\n", b[r - l + 2 - k]);
	}
	return 0;
}