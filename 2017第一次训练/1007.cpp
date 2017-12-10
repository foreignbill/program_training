#include<bits/stdc++.h>
#define N 1000010
using namespace std;
typedef long long ll;
int a[N],n;ll ans=0;
/*
首先我们已知对于自动机状态pre
来说，我们已知它最后插入的节点为t，由已知性质可得，该节点可表示[min(t),max(t)]区间长度的后缀，
设插入t的状态为cur，此时我们将插入x节点，那么父节点拓展可知，它可以表示[min(x),max(x)]区间长度的后缀
由自动机的定义可知，max(t)+1=min(x),所以对于一个新插入节点可知，新产生的新串为" min(x)-max(t) "
*/
struct Suffix_Automaton{
    int cnt,last,l[N<<1],fa[N<<1];
    map<int,int> ch[N<<1];
    Suffix_Automaton(){cnt=last=1;}
    void ins(int c){
        int p=last,np=++cnt;last=np;l[np]=l[p]+1;
        for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
        if(!p)fa[np]=1;
        else{
            int q=ch[p][c];
            if(l[p]+1==l[q])fa[np]=q;
            else{
                int nq=++cnt;l[nq]=l[p]+1;
                ch[nq]=ch[q];
                //memcpy(ch[nq],ch[q],sizeof(ch[q]));
                fa[nq]=fa[q];fa[np]=fa[q]=nq;
                for(;p&&ch[p][c]==q;p=fa[p])ch[p][c]=nq;
            }
        }
        ans+=(ll)l[np]-(ll)l[fa[np]];
    }
}sam;
int main(){
    int n;
    int x;
    cin>>n;
    ans=0;
    for(int i=1;i<=n;i++) {
        scanf("%d",&x);
        sam.ins(x);
    }printf("%lld\n",ans);
    return 0;
}