#include <cstdio>
#include <cstdlib>

int main()
{
        int n;
        while((scanf("%d",&n))!=EOF){
                if(n==0){
                        continue;
                }
                int f_n=0;
                int f_z=0;
                int f_p=0;
                double val;
                for(int i=0;i<n;i++){
                        scanf("%lf",&val);
                        if(val>0){f_p++;}
                        else if(val==0){f_z++;}
                        else {f_n++;}
                }
                printf("%d %d %d\n",f_n,f_z,f_p);
        }
        return 0;
}