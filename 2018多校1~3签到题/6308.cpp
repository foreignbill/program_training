#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define V vector<int>
#define debug(a) cerr<<#a<<"=="<<a<<endl
typedef long long  LL;
using namespace std;
//模拟题

int t;
char s[100];
int main() {
    cin>>t;
    int a,b;
    while(t--) {
        scanf("%d%d",&a,&b);
        scanf("%s",s);
        int len = strlen(s);
        int x = 0,y=len;
        for(int i=0;i<len;i++) {
            if(s[i]=='+'||s[i]=='-') x = i;
            if(s[i]=='.') y = i;
        }
        int ans1=0,ans2=0;
        for(int i=x+1;i<=y-1;i++) {
            ans1 = ans1*10 + s[i]-'0';
        }
        for(int i=y+1;i<len;i++) {
            ans2 = ans2*10 + s[i]-'0';
        }
        int all = a*60+b-480;
        int t = ans1*60+ans2*6;
        int ans;
        if(s[3]=='+') {
            ans = all + t;
        }
        else {
            ans = all - t;
        }
        if(ans < 0)
            ans += 1440;
        int aa = ans/60%24;
        int bb = ans%60;
        printf("%02d:%02d\n",aa,bb);
    }
    return 0;
}