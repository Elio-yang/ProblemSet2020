#include <cstdio>
#include <cstdlib>

int main()
{
        int m,n;
        while(scanf("%d %d",&m,&n)!=EOF){
                if(m>n){
                        int tmp=m;
                        m=n;
                        n=tmp;
                }
                int size=n-m+1;
                int ans_o=0;
                int ans_e=0;
                int* val=(int*)malloc(sizeof(int)*size);
                for(int i=0;i<size;i++){
                        val[i]=m+i;
                        if(val[i]%2!=0){
                                ans_o+=(val[i]*val[i]*val[i]);
                        }else{
                                ans_e+=(val[i]*val[i]);
                        }
                }
                printf("%d %d\n",ans_e,ans_o);
        }
        return 0;
}
