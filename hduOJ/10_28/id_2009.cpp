#include <cstdio>
#include <cmath>

#define power(val,n) ({                         \
                        int ans=1;              \
                        for(int i=1;i<=n;i++){  \
                                ans*=val;       \
                        }                       \
                        ans;                    \
                     })
int main()
{
        int n,m;
        while(scanf("%d %d",&n,&m)!=EOF){
                double sum=n+0.0;
                double term=n+0.0;
                for(int i=1;i<=m-1;i++){
                        term=sqrt(term);
                        sum+=term;
                }
                printf("%.2lf\n",sum);
        }
        return 0;
}