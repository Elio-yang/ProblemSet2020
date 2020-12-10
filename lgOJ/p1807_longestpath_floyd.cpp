//
// Created by ELIO on 2020/12/9.
//

/*
  1.如果全是 正权值  所有的权值取反 floyd or bellman-ford spfa
 求出最小的路径，取相反数
  2.如果全是 负权值  所有的权值取反
  求出最小路径，取相反数
  3.如果有正有负 整数取反，负数取反
  此时最短 负的最多，正的最少 结果取反即可

  综上：权值取反，求最短路径，输出相反数
 */

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=1505;
const int inf=0x3f3f3f3f;
struct node{
        int v;
        int w;
        node(int V,int W):v(V),w(W){
        }
};
int dis[maxn][maxn];
class Graph{
public:

        int n;
        int e;
        Graph(int N,int E):n(N),e(E){
                memset(dis,0x3f,sizeof(dis));
                for (int i = 1; i <= n; i++) {
                        dis[i][i]=0;
                }
        }
        int floyd();
};
int Graph::floyd()
{
        int i,j,k;
        for ( k = 1; k <=n ; k++) {
                for (i=1;i<=n;i++){
                        for(j=1;j<=n;j++){
                                if (dis[i][k]!=inf&&dis[k][j]!=inf){
                                        dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
                                        /*FLOYD 模板背熟*/
                                }
                        }
                }
        }
        return dis[1][n];
}

int main()
{
        int n,m;
        scanf("%d %d",&n,&m);
        Graph G(n,m);
        for (int i = 0; i < m; i++) {
                int u,v,w;
                scanf("%d %d %d",&u,&v,&w);
                dis[u][v]=min(-w,dis[u][v]);
        }
        int ans=G.floyd();
        if (ans==inf){
                printf("-1\n");
        }else{
                printf("%d\n",-ans);
        }

        return 0;
}