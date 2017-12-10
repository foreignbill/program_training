#include <bits/stdc++.h>
using namespace std;
const int N = 2510;
const int inf = (int) 1e9;

vector< pair<int, int> > g[N];
int d[N];

int main() {
	int n, m, st, final;
	scanf("%d %d %d %d", &n, &m, &st, &final);
	st--; final--;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		x--; y--;
		g[x].emplace_back(y, z);
		g[y].emplace_back(x, z);
	}
	fill(d, d + n, inf);
	set< pair<int, int> > s;
	d[st] = 0;
	s.emplace(0, st);
	while (!s.empty()) {
		int i = s.begin()->second;
		s.erase(s.begin());
		for (auto &e : g[i]) {
			int to = e.first;
			int dt = e.second;
			if (d[i] + dt < d[to]) {
				s.erase(make_pair(d[to], to));
				d[to] = d[i] + dt;
				s.emplace(d[to], to);
			}
		}
	}
	printf("%d\n", d[final]);
	return 0;
}