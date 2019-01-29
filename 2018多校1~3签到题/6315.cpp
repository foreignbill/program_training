#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5+555;
int a[maxn],n,q;
int b[maxn];

inline int lowbit(int x) {
  return x & -x;
}

inline void add(int x) {
  while(x<=n) {
    b[x]++;
    x+=lowbit(x);
  }
}

inline int get(int x){
  if(!x) return 0;
  int ret = 0;
  while(x) {
    ret += b[x];
    x-=lowbit(x);
  }
  return ret;
}

struct node{
  int x,d;
  node(int _x=0,int _d=0):x(_x),d(_d){}
}T[maxn<<2];

vector<int> v;

void build(int id,int l,int r) {
  if(l==r) {
    T[id].x=a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(id<<1,l,mid);
  build(id<<1|1,mid+1,r);
  T[id].x = min(T[id<<1].x,T[id<<1|1].x);
  T[id].d = 0;
}

void pushdown(int id) {
  if(T[id].d) {
    T[id<<1].d += T[id].d;
    T[id<<1|1].d += T[id].d;
    T[id<<1].x += T[id].d;
    T[id<<1|1].x += T[id].d;
    T[id].d = 0;
  }
}

void dfs(int id,int l,int r) {
  if(T[id].x > 0) return;
  if(l==r) {
    T[id].x = a[l];
    v.push_back(l);
    return;
  }
  pushdown(id);
  int mid = (l + r) >> 1;
  if(T[id<<1].x<=0) dfs(id<<1,l,mid);
  if(T[id<<1|1].x<=0) dfs(id<<1|1,mid+1,r);
  T[id].x = min(T[id<<1].x,T[id<<1|1].x);
}

void modify(int id,int L,int R,int l,int r) {
  if(L<=l&&r<=R) {
    T[id].x += -1;
    T[id].d += -1;
    dfs(id,l,r);
    return;
  }
  pushdown(id);
  int mid = (l + r) >> 1;
  if(L <= mid) modify(id<<1,L,R,l,mid);
  if(mid < R) modify(id<<1|1,L,R,mid+1,r);
  T[id].x = min(T[id<<1].x,T[id<<1|1].x);
}

/*
  线段树
  考虑到发生改变的操作数目为 n + n / 2 + n / 3 + ... + n / n 约为 nln n个。
*/

int main () {
  while(~scanf("%d%d", &n, &q)) {
    for(int i=1;i<=n;i++)
      scanf("%d",&a[i]);
    build(1,1,n);
    memset(b,0,sizeof b);
    char ch[20];
    int l,r;
    for(int i=1;i<=q;i++) {
      scanf("%s%d%d",ch,&l,&r);
      if(ch[0]=='a') {
        v.clear();
        modify(1,l,r,1,n);
        //putchar('#');
        for(auto ep:v){
          add(ep);
          //cout << ep << " ";
        }
        //puts("");
      } else {
        printf("%d\n",get(r)-get(l-1));
      }
    }
  }
  return 0;
}