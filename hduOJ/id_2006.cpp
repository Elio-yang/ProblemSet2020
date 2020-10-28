#include <cstdio>
#include <cstdlib>
int main()
{
        int n;
        while(scanf("%d",&n)!=EOF){
                int ans=1;
                int *val=(int*)malloc(sizeof(int)*n);
                for(int i=0;i<n;i++){
                        scanf("%d",val+i);
                        if((val[i]&(0x1))==1){
                                ans*=val[i];
                        }
                }
                free(val);
                printf("%d\n",ans);
        }
        return 0;
}