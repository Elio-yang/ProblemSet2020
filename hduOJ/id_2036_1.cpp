#include <cstdio>
#include <cmath>
#include <algorithm>
/*要考虑凹多边形*/
#define len(x1,y1,x2,y2) (sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)))

#define x 0
#define y 1

int main()
{
        int n;
        while(~scanf("%d",&n)){
                if(!(n>=3&&n<=100)){
                        continue;
                }
                int arr[n][2];
                for(int i=0;i<n;i++){
                        scanf("%d %d",&arr[i][x],&arr[i][y]);
                }
                double S=0.0;
                for(int i=1;i<=n-2;i++){
                        double l_0_i=len(arr[0][x],arr[0][y],arr[i][x],arr[i][y]);
                        double l_i_n=len(arr[i][x],arr[i][y],arr[i+1][x],arr[i+1][y]);
                        double l_n_0=len(arr[i+1][x],arr[i+1][y],arr[0][x],arr[0][y]);
                        double p=(l_i_n+l_n_0+l_0_i)/2;
                        double arg1=p-l_0_i;
                        double arg2=p-l_i_n;
                        double arg3=p-l_n_0;
                        double s_i=sqrt(p*arg1*arg2*arg3);
                        S+=s_i;
                }
                printf("%.1lf\n",S);
        }
        return 0;
}