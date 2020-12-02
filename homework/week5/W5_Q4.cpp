#include <cstdio>
#define size 310
using namespace std;
int dis[size][size];
int floyd(int n)
{
        int num=0;
        for (int i = 0; i < n; i++) {
                for (int j = i+1; j < n; j++) {
                        for (int k = 0; k < n; k++) {
                                if(i == k || j == k)continue;
                                if(dis[i][j] == (dis[i][k] + dis[k][j])){
                                        num++;
                                        dis[i][j]= dis[i][k] + dis[k][j];
                                        break;
                                }
                        }
                }
        }
        return num;
}
int main()
{
        int n;
        scanf("%d",&n);
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        scanf("%d",&dis[i][j]);
                }
        }
        int Cn2=(n-1)*(n)/2;
        int k=floyd(n);
        printf("%d",Cn2-k);
        return 0;
}