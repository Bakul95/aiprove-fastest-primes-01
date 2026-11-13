#include <stdio.h>
#include <string.h>
static unsigned char c[2500001];
int main(void){
    int n; if(scanf("%d",&n)!=1) return 0;
    if(n<2){ puts("0"); return 0; }
    int m=(n+1)/2, cnt=1;
    memset(c,0,m);
    for(int p=3;(long)p*p<=n;p+=2) if(!c[p/2])
        for(long j=(long)p*p;j<=n;j+=2L*p) c[j/2]=1;
    for(int i=1;i<m;i++) if(!c[i]) cnt++;
    printf("%d\n",cnt);
    return 0;
}
