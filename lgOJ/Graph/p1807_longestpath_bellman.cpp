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
int dis[maxn];
class Graph{
public:

        int n;
        int e;
        vector<node>Adj[maxn];
        Graph(int N,int E):n(N),e(E){
        }
        int bellman(int s);
};
bool flag= false;

int Graph::bellman(int s)
{
        /*
          模板： 1.初始化 dis[s]=0 dis[i]=inf
                2.n-1轮操作: 遍历所有的边，看能不能松弛
                3.遍历所有的边，看能不能再松弛，如果能就是有负环
         */
        memset(dis,0x3f,sizeof(dis));
        dis[s]=0;
        for (int i = 1; i <n ; i++) {
                //n-1轮操作，再遍历所有的边
                for (int j = 1; j <=n ; j++) {
                        for (int k = 0; k <Adj[j].size() ; k++) {
                                //松弛操作 j--->Adj[j][k].v
                                int v=Adj[j][k].v;
                                if (dis[j]+Adj[j][k].w<dis[v]){
                                        dis[v]=dis[j]+Adj[j][k].w;
                                }
                        }
                }
        }
        for (int j = 1; j <=n ; j++) {
                for (int i = 0; i <Adj[j].size() ; i++) {
                        //松弛操作 j--->Adj[j][i].v
                        int v=Adj[j][i].v;
                        if (dis[j]+Adj[j][i].w<dis[v]){
                                flag= true;
                        }
                }
        }
        return dis[n];
}


int main()
{
        int n,m;
        scanf("%d %d",&n,&m);
        Graph G(n,m);
        for (int i = 0; i < m; i++) {
                int u,v,w;
                scanf("%d %d %d",&u,&v,&w);
                node new_node(v,-w);
                G.Adj[u].push_back(new_node);
        }
        int ans=G.bellman(1);
        if (ans==inf){
                printf("-1\n");
        }else{
                printf("%d\n",-ans);
        }

        return 0;
}