//
// Created by ELIO on 2020/12/10.
//

//#pragma GCC optimize(3,"Ofast","inline")
//#pragma GCC optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
//#include <immintrin.h>
//#include <emmintrin.h>
/*
  从1到其余n-1个点是1到多的最短路径，可以用Dijkstra Bellman SPFA
  从其它n-1到1是多到1的最短路径，怎样转化一下？？
        不妨逆转所有的边，那么从节点i--->k--->1 可以化为 1---->k---->i
        权值不变，从而，反向建立邻接表以后可以再次使用Dijkstra


 可否Floyd？ 可以 -O2 优化

 */

#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;
const int maxn = 1005;
const int inf = 0x3f3f3f3f;
struct node {
        int v;
        int w;

        node(int V = 0, int W = 0) : v(V), w(W)
        {}

        bool operator<(const node &b) const
        {
                return w > b.w;
        }
};

bool vis[maxn] = {false};
int dis[maxn];
int D[maxn][maxn];

class City {
public:
        int n;
        int e;
        vector<node> Adj1[maxn + 5];
        vector<node> Adj2[maxn + 5];

        City(int N, int M) : n(N), e(M)
        {}

        void Dijkstra(int s, vector<node> adj_t[]);
        void Floyd();

        long long solve();
        long long Solve();
};

void City::Dijkstra(int s, vector<node> adj_t[])
{
        memset(dis, 0x3f, sizeof(dis));
        memset(vis, 0, sizeof(vis));

        /*Dijkstra 堆优化
                1.优先队列 小顶堆
                2.入队源点
                3.队列非空 则：
                        a. 队首元素弹出
                        b.是否访问
                                1.访问则 continue
                                2.未访问则标记
                                        a.访问邻接，如果没被访问且可以更新dis 则更新，并入队

         */
        priority_queue<node> q;
        dis[s] = 0;
        q.push(node{s, 0});
        while (!q.empty()) {
                node tmp = q.top();
                q.pop();
                if (vis[tmp.v])continue;
                vis[tmp.v] = true;
                for (int i = 0; i < adj_t[tmp.v].size(); i++) {
                        node cur = adj_t[tmp.v][i];
                        if (!vis[cur.v] && (dis[tmp.v] + cur.w < dis[cur.v])) {
                                dis[cur.v] = dis[tmp.v] + cur.w;
                                q.push(node{cur.v, dis[cur.v]});
                        }
                }
        }

}
long long City::solve()
{
        long long ans1 = 0;
        Dijkstra(1, Adj1);
        for (int i = 2; i <= n; i++) {
                ans1 += dis[i];
        }
        Dijkstra(1, Adj2);
        for (int i = 2; i <= n; i++) {
                ans1 += dis[i];
        }
        return ans1;
}

void City::Floyd()
{
        for (int i = 1; i <=n ; i++) {
                D[i][i]=0;
        }
        for(int k=1;k<=n;k++){
                for (int i = 1; i <=n ; i++) {
                        for (int j = 1; j <=n ; j++) {
                                if (D[i][k]!=inf&&D[k][j]!=inf){
                                        D[i][j]=min(D[i][k]+D[k][j],D[i][j]);
                                }
                        }
                }
        }
}

long long City::Solve()
{
        Floyd();
        int ans=0;
        for (int i = 2; i <=n ; i++) {
                ans+=D[1][i];
        }
        for (int i = 2; i <=n ; i++) {
                ans+=D[i][1];
        }
        return ans;

}

int main()
{
        int n, m;
        scanf("%d %d", &n, &m);
//        City G(n, m);
//        for (int i = 0; i < m; i++) {
//                int u, v, w;
//                scanf("%d %d %d", &u, &v, &w);
//                node n1(v, w);
//                G.Adj1[u].push_back(n1);
//                /* 反向建图 Dijkstra 堆优化*/
//                node n2(u, w);
//                G.Adj2[v].push_back(n2);
//        }
//        long long ans = G.solve();
//        printf("%lld", ans);
        City G(n,m);
        memset(D,0x3f,sizeof(D));
        for (int i = 0; i < m; i++) {
                int u,v,w;
                scanf("%d %d %d",&u,&v,&w);
                /* 要判断是否重复*/
                D[u][v]=min(w,D[u][v]);
        }
        long long ans=G.Solve();
        printf("%d",ans);
        return 0;
}