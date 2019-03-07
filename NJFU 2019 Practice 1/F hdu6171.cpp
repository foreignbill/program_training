#include <bits/stdc++.h>

using namespace std;

map<int,int> mp1;
map<int,int> mp2; 
struct node{
    int a[22];
    int s;
    // Debug
    void print(){
        for(int i=0;i<21;i++){
            printf("%d ",a[i]);
            if(i==0 || i==2 || i==5 || i==9 || i==14 || i==20) puts("");
        }
    }
};
int pur[]={0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 0};
node now;
int base[22];

queue<node> Q;
int get(int pur[]){
    int ret = 0;
    for(int i=0;i<21;i++)
        ret += base[i+1]*pur[i];
    return ret;
}

const int POS1[]={-1,-1,0 ,-1,1 ,2 ,-1,3 ,4 ,5 ,-1,6 ,7 ,8 ,9 ,-1,10,11,12,13,14};
const int POS2[]={-1,0 ,-1,1 ,2 ,-1,3 ,4 ,5 ,-1,6 ,7 ,8 ,9 ,-1,10,11,12,13,14,-1};
const int POS3[]={1 ,3 ,4 ,6 ,7 ,8 ,10,11,12,13,15,16,17,18,19,-1,-1,-1,-1,-1,-1};
const int POS4[]={2 ,4 ,5 ,7 ,8 ,9 ,11,12,13,14,16,17,18,19,20,-1,-1,-1,-1,-1,-1};

int getpos(int pos,int i){
    if(i==1){
        return POS1[pos];
    }
    if(i==2){
        return POS2[pos];
    }
    if(i==3){
        return POS3[pos];
    }
    if(i==4){
        return POS4[pos];
    }
}

void bfs1(){
    mp1.clear();
    int purpose = get(pur);
    mp1[purpose] = 0;
    while(!Q.empty()) Q.pop();
    node tmp;
    memcpy(tmp.a,pur,sizeof pur);
    tmp.s=0;
    Q.push(tmp);
    while(!Q.empty()){
        node now = Q.front();
        Q.pop();
        if(now.s>10) return;
        int pos = now.a[21];
        for(int i=1;i<=4;i++){
            int posto = getpos(pos,i);
            if(posto == -1) continue;
            node tmp = now;
            swap(tmp.a[pos],tmp.a[posto]);
            int key = get(tmp.a);
            if(mp1.find(key)!=mp1.end()) continue;
            tmp.s++;tmp.a[21]=posto;
            mp1[key]=tmp.s;
            Q.push(tmp);
        }
    }
}

int bfs2(node now){
    mp2.clear();
    int key = get(now.a);
    if(mp1.find(key)!=mp1.end()){
        return mp1[key];
    }
    mp2[key]=0;
    while(!Q.empty()) Q.pop();
    now.s=0; 
    Q.push(now);
    while(!Q.empty()){
        node nownow = Q.front();
        Q.pop();
        if(nownow.s>10) return -1;
        int pos = nownow.a[21];
        for(int i=1;i<=4;i++){
            int posto = getpos(pos,i);
            if(posto == -1) continue;
            node tmp = nownow;
            swap(tmp.a[pos],tmp.a[posto]);
            key = get(tmp.a);
            if(mp1.find(key)!=mp1.end()){
                return mp1[key]+nownow.s+1;
            }
            if(mp2.find(key)!=mp2.end()){
                continue;
            }
            tmp.s++;tmp.a[21]=posto;
            mp2[key]=tmp.s;
            Q.push(tmp);
        }
    }
    return -1;
}

int main(){
    // base[] for hash
    base[0]=1;
    for(int i=1;i<=21;i++)
        base[i]=base[i-1] * 237 + 19260817;
    bfs1();
    int T;
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<21;i++){
            scanf("%d",&now.a[i]);
            if(now.a[i]==0) now.a[21]=i;
        }
        now.s = 0;
        int ans = bfs2(now);
        if(ans == -1 || ans >20) puts("too difficult");
        else printf("%d\n",ans);
    }
    return 0;
} 
