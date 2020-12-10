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
#include <queue>

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
bool in_stack[maxn];
class Graph{
public:

        int n;
        int e;
        vector<node>Adj[maxn];
        Graph(int N,int E):n(N),e(E){
        }
        int spfa_bfs(int s);
        void spfa_dfs(int s);
};

bool flag= false;

int Graph::spfa_bfs(int s)
{
        /*
         spfa框架：
                1.相关的数组： nums[] 每个元素的入队次数 如果 nums[v]>=n 则说明有负环
                              in_queue[] 判断这个元素是否在队列中，每次入队和出队都要记得更新
                              dis[i] 到i的最短距离
                2.框架：
                        a. 源点入队，标记
                        b.队列非空，则：
                                b1. 出队一个元素，访问其邻接的顶点，看能否松弛
                                b2.若能松弛，则松弛，判断这个顶点是否再队列中，不在则入队
                                b3.判断这个顶点的入队次数 若>=n则说明有环，返回
                        c.无环
                3.注意：每次的队列操作都要记得更新 nums 跟 in_queue数组
         */
//        int nums[n];//如队次数
        bool in_queue[n];//是否在队列中
        memset(in_queue,0,sizeof(in_queue));
//        memset(nums,0,sizeof(nums));
        memset(dis,0x3f,sizeof(dis));
        dis[s]=0;//初始化
        queue<int> q;
        q.push(s);
//        nums[s]++;
        in_queue[s]= true;
        while (!q.empty()){
                int u=q.front();
                q.pop();
                //别忘了出队列的时候标记一下
                in_queue[u]= false;
                for (int i = 0; i < Adj[u].size(); i++) {
                        //u--->Adj[u][i].v
                        int v=Adj[u][i].v;
                        if (dis[u]+Adj[u][i].w<dis[v]){
                                dis[v]=dis[u]+Adj[u][i].w;
                        }
                        if (!in_queue[v]){
                                q.push(v);
//                                nums[v]++;
                                in_queue[v]= true;
//                                if (nums[v]>n-1){
//                                        flag= true;
//                                        return flag;
//                                }
                        }

                }
        }
        return dis[n];

//        return flag


}

void Graph::spfa_dfs(int s)
{
        /*
         需要判断负环的时候，使用dfs 效果更好
         */
        in_stack[s]= true;
        for (int i = 0; i < Adj[s].size(); i++) {
                int v=Adj[s][i].v;
                if (dis[s]+Adj[s][i].w<dis[v]){
                        dis[v]=dis[s]+Adj[s][i].w;
//                        if (!in_stack[s]){
//                                //这个s不在in_stack中
//                                spfa_dfs(v);
//                        }else{
//                                //有环
//                               // return 1;
//                        }
                        spfa_dfs(v);
                }
        }
        in_stack[s]= false;
       // return 0;
}

/*
 int spfa_dfs(int u)
{
    vis[u]=1;
    for(int k=f[u]; k!=0; k=e[k].next)
    {
        int v=e[k].v,w=e[k].w;
        if( d[u]+w < d[v] )
        {
            d[v]=d[u]+w;
            if(!vis[v])
            {
                if(spfa_dfs(v))
                    return 1;
            }
            else
                return 1;
        }
    }
    vis[u]=0;
    return 0;
}
 */

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

        memset(in_stack,0,sizeof(in_stack));
        memset(dis,0x3f,sizeof(dis));
        dis[1]=0;
        G.spfa_dfs(1);
        int ans=dis[n];
        if (ans==inf){
                printf("-1\n");
        }else{
                printf("%d\n",-ans);
        }

        return 0;
}