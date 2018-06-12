#include <cstdio>
 
int n,a,cnt,x,res;
 
int main(){
    while(~scanf("%d",&n)){
	    cnt=x=0;
	    for(int i=1;i<=n;i++){
	        scanf("%d",&x);
	        if(x==res) cnt++;
	        else {
	            if(cnt==0){
	                res=x;
	                cnt++;
	            } else cnt--;
	        }
	    }
	    printf("%d\n",res);
	}
    return 0;
}
/*
	乱搞
*/