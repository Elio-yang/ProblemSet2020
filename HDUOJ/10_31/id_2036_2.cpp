#include <cstdio>
#include <algorithm>
/*
Shoelace Theorem
顺时针：S=1/2*|Sum(i=1,n) x[i]*y[i+1]-y[i]*x[i+1]|(n+1=1)
逆时针：不用绝对值
*/
int main()
{
        int n;
        while(~scanf("%d",&n)){
                if(!(n>=3&&n<=100)){
                        continue;
                }
                double x[110],y[110];
                double ans=0.0;
                for(int i=1;i<=n;i++){
                        scanf("%lf %lf",&x[i],&y[i]);
                }
                for(int i=1;i<=n;i++){
                        int index=i+1;
                        if(index==n+1){
                                index=1;
                        }
                        ans+=x[i]*y[index]-y[i]*x[index];
                }
                printf("%.1lf\n",ans/2.0);
        }

        return 0;
}