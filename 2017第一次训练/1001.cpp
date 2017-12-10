#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[20];
ll cnt[26];
int main(){
	f[0]=1;for(ll i=1;i<=15;i++) f[i]=f[i-1]*i;
	string st;cin>>st;
	for(int i=0;i<(int)st.size();i++) cnt[st[i]-'a']++;
	ll res=f[st.size()];
	for(int i=0;i<26;i++) res/=f[cnt[i]];
	cout<<res;
	return 0;
}