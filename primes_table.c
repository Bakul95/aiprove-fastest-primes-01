#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char**argv){
    int n; if(scanf("%d",&n)!=1) return 0;
    if(n<2){ puts("0"); return 0; }
    char path[1024]; const char *dir=".";
    if(argc>0){ const char *s=strrchr(argv[0],'/'); if(s){ size_t l=s-argv[0]; if(l>1023)l=1023; memcpy(path,argv[0],l); path[l]=0; dir=path; } }
    char full[1100]; snprintf(full,sizeof full,"%s/sieve.bin",dir);
    FILE *f=fopen(full,"rb"); if(!f){ f=fopen("sieve.bin","rb"); if(!f) return 1; }
    int m=(n+1)/2, nb=(m+7)/8;
    unsigned char *b=malloc(nb); if(fread(b,1,nb,f)!=(size_t)nb) return 1; fclose(f);
    for(int i=m;i<nb*8;i++) b[i/8]&=~(1u<<(i%8)); /* clear bits past N */
    long long comp=0;
    int fullw=nb/8; unsigned long long *w=(unsigned long long*)b;
    for(int i=0;i<fullw;i++) comp+=__builtin_popcountll(w[i]);
    for(int i=fullw*8;i<nb;i++) comp+=__builtin_popcount(b[i]);
    /* bits counted cover indices 0..nb*8-1; indices >= m are zero in file; index 0 (number 1) is marked composite */
    long long oddprimes=(long long)(m-1)- (comp-1); /* subtract bit0, then odd indices 1..m-1 that are composite */
    printf("%lld\n",1+oddprimes);
    return 0;
}
