#include <bits/stdc++.h>

using namespace std;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
int vis[110][110];
char s[110][110];
int n,m;
int pan(int x,int y){
    if(x<0||y<0) return -1;
    if(x>=n||y>=m) return -1;
    if(s[x][y]=='0') return 0;
    return 1;
}
void dfs1(int i,int j){
    int nowx,nowy;
    vis[i][j]=1;
    for(int i1=0;i1<4;i1++){
        nowx=i+dx[i1];
        nowy=j+dy[i1];
        if(pan(nowx,nowy)==1&&!vis[nowx][nowy]) dfs1(nowx,nowy); 
    }
}
int dfs2(int i,int j){
    int nowx,nowy;
    vis[i][j]=1;
    int ret=1;
    for(int i1=0;i1<4;i1++){
        nowx=i+dx[i1];
        nowy=j+dy[i1];
        if(pan(nowx,nowy)==0&&!vis[nowx][nowy]) if(dfs2(nowx,nowy)==0) ret=0;
        if(pan(nowx,nowy)==-1) ret=0;
    }
    return ret;
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++)
            scanf("%s",s[i]);
        memset(vis,0,sizeof(vis));
        int ans=0,tmp=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            if(!vis[i][j]){
                if(s[i][j]=='1'){
                    ans++;
                    dfs1(i,j);
                }
                else if(dfs2(i,j)==1) tmp++;
            }
        if(ans==1){
            if(tmp==1) puts("0");
            else if(tmp==0) puts("1");
            else puts("-1");
        }
        else puts("-1");
    }
    return 0;
}