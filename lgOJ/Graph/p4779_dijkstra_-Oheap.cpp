/*
 * Dijkstra:堆优化
 *      1.初始化dis[s]=0,dis[i]=inf，入队源点q.push(make_pair(dis[s],1))
 *      2.循环（队列非空）
 *              a.出队一个元素 看是否访问，未访问则 访问 该元素
 *              b. 访问该顶点的邻接顶点，并更新其dis 入队邻接顶点
 * */

#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=100010;
int dis[maxn];
bool vis[maxn];
struct node{
        int v;
        int w;
        node(int V,int W):v(V),w(W){}
        bool operator<(const node b) const{
                //返回true说明 this < b this排在后边 即小的在前面 小顶堆
                return w>b.w;
        }
};

/*
 * 可以用pair<int,int>+greater<>建立小顶堆
 * 第一个元素放w（dis） 第二个元素放编号
 * 先按照first升序，再按照second升序
 * */
vector<node> Adj[maxn];
int n,m,s;
void Dijkstra(int S){
        /*堆优化的Dijkstra 主要是每次找最小的dis的v*/
        priority_queue<node> Q;
        dis[S]=0;
        Q.push(node(S,0));

        while (!Q.empty()){
                node tmp = Q.top();
                Q.pop();
                int t_v = tmp.v;
                if (vis[t_v]) continue;
                vis[t_v] = true;
                for (int j = 0; j < Adj[t_v].size(); j++) {
                        int v = Adj[t_v][j].v;
                        if (!vis[v] && dis[t_v] + Adj[t_v][j].w < dis[v]) {
                                dis[v] = dis[t_v] + Adj[t_v][j].w;
                                Q.push(node(v, dis[v]));
                        }
                }
        }
}
int main()
{
        scanf("%d %d %d",&n,&m,&s);
        for (int i = 0; i < m; i++) {
                int u,v,w;
                scanf("%d %d %d",&u,&v,&w);
                node new_node(v,w);
                Adj[u].push_back(new_node);
        }
        memset(dis,0x3f,sizeof(dis));
        Dijkstra(s);
        for (int i = 1; i <=n ; i++) {
                printf("%d ",dis[i]);
        }
        return 0;
}