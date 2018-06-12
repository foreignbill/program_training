#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

namespace LIS {
	const int maxn = 1e5 + 5;
	int S[maxn],top;
	int solve(vector<int> v) {
		memset(S,0,sizeof S);
		top = 0;
		for(int i=0;i<(int)v.size();i++){
			int x = v[i];
			if(top == 0 || x > S[top]){
				S[++top] = x;
			} else {
				int pos = lower_bound(S+1,S+1+top,x) - S;
				S[pos] = x;
			}
		}
		return top;
	}
};

int main () {
	vector<int> v;
	int x,n;
	while(~scanf("%d",&n)){
		v.clear();
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			v.push_back(x);
		}
		cout << LIS::solve(v) << endl;
	}
	return 0;
}