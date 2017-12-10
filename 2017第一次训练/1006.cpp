#include <cstdio>
#define maxn 1000005
int f[maxn];
int main() {
	int i, n;
	f[1] = f[2] = 1;
	scanf("%d", &n);
	for (i = 3; i <= n; i++) {
		f[i] = ((f[i - 1] + f[i - 2]) % 1000000007);
	}
	printf("%d", f[n]);
	return 0;
}