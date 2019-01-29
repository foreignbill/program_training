#include <iostream>
#include <cstdio>
#include <algorithm>
#define fast() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define V vector<int>
typedef long long  ll;
using namespace std;
//template
const int maxn = 100000+100;
int a[maxn],n;
int temp[maxn];
ll ans = 0;
void merge(int low,int mid,int high) {
    //printf("merge: %d %d %d \n",low,mid,high);
    int i = low, j = mid + 1;
    int k = low;
    while(i <= mid && j <= high) {
        if(a[i] <= a[j]) temp[k++] = a[i++];
        else {
            ans += j - k;
            temp[k++] = a[j++];
        }
    }
    while(i<=mid) temp[k++] = a[i++];
    while(j<=high) temp[k++] = a[j++];
    for(int i=low;i<=high;i++) a[i] = temp[i];
}
void sort(int l,int r) {
    if(l<r) {
        int mid = (l+r)>>1;
        sort(l,mid);
        sort(mid+1,r);
        merge(l,mid,r);
    }
}
int x,y;

void out(__int128 res) {
    int base[64];
    int top = 0;
    if(res == 0) {
        puts("0");
    } else {
        while(res) {
            base[top++]=res%10;
            res/=10;
        }
        for(int i=top-1;i>=0;i--)
            putchar(base[i]+'0');
        puts("");
    }
}

// 本质是求逆序对数目

int main() {
    //freopen("in.txt","r",stdin);
    while(scanf("%d%d%d",&n,&x,&y)!=EOF) {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        ans = 0;
        sort(1,n);
        __int128 res = 1;
        res = res * ans;
        if(x<=y) res = res * x;
        else res = res * y;
        out(res);
    }
    return 0;
}