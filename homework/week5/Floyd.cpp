#include <cstdio>
#include <cstring>
#include <algorithm>
#define size 110
#define inf 16843009
using namespace std;
int G[size][size];
int dis[size][size];
int P[size][size];

bool floyd(int n)
{
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        dis[i][j] = G[i][j];
                }
        }
        for (int i = 0; i < n; i++) {
                dis[i][i]=0;
        }/*d[i][i]一定要初始化为0*/
        for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                                if(dis[i][j] > (dis[i][k] + dis[k][j])){
                                        dis[i][j]= dis[i][k] + dis[k][j];
                                }
                        }
                }
        }
        for (int i = 0; i < n; i++) {
                if(dis[i][i] < 0){return true;}
        }
        return false;
}
int main()
{
        int n,e,m;
        while ((scanf("%d %d %d",&n,&e,&m))!=EOF){

                memset(G,1,sizeof(G));
                for(int i=0;i<e;i++){
                        int i1,i2,w;
                        scanf("%d %d %d",&i1,&i2,&w);
                        G[i1][i2]=w;
                }

                bool f=floyd(n);

                for(int i=0;i<m;i++){
                        int x,y;
                        scanf("%d %d",&x,&y);
                        if(!f)
                        {
                                if(dis[x][y] == inf){
                                        printf("none\n");
                                }else{
                                        printf("%d\n", dis[x][y]);
                                }
                        }else{
                                continue;
                        }
                }
                if(f){
                        printf("negative circle\n");
                }
        }
        return 0;
}