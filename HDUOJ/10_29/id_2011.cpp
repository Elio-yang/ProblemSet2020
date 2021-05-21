#include <cstdio>
#include <cstdlib>
int main()
{
        int m;
        int n;
        scanf("%d",&m);
        int ops[m];
        for(int i=0;i<m;i++){
                scanf("%d",&ops[i]);
        }
        double ans;
        for(int l=0;l<m;l++){
                ans=0.0;
                for(int j=1;j<=ops[l];j++){
                        int f=0;
                        if(j&(0x1)==1){
                                f=1;
                        }else{
                                f=-1;
                        }
                        double term=(f*1.0)/j;
                        ans+=term;
                }
                printf("%.2lf\n",ans);
        }

        system("pause");        
        return 0;
}