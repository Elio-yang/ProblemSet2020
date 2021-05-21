/*
 * Prim算法：<找顶点>
 *      1.初始化 dis[s]=0 dis[i]=inf
 *      2.开始循环（n轮）
 *              a.找到距离U 最近的顶点
 *              b.如果未访问，则访问该顶点 否则循环继续
 *              c.ans更新:dis=min(w,dis)  cnt更新:cnt++
 *              d.以该顶点未为中继，访问其邻接顶点，更新dis
 *      3.如果cnt==n 返回ans
 *
 *  Prim算法中的dis是该顶点到被访问的集合的距离，只能是用w更新
 *
 * -Oheap:堆优化
 *  pair<int,int> 第一个存dis 第二个存节点编号
 *  greater<> 按照升序 先排first 再排second
 *
 *  先入队 make_pair(0,1)
 *  之后循环(!q.empty()&&cnt<n)
 *      出队一个元素，看是否被访问，若未被访问则访问
 *      之后访问这个顶点的邻接的时候，再入队相邻接的顶点
 *
 *  注意：
 *      1.与Dijkstra 的堆优化类似。 注意联想记忆
 *      2.dis的意义是？
 *      3.如何设置优先队列的元素类型？ pair<int,int> 为何这样设置？？
 *              first是需要更新的距离，也是优先级首先排序的
 *              second是顶点编号，也已用来更新vis 也可以用来访问邻接表
 *
 * */

#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
const int maxn = 5005;
const int inf = 0x3f3f3f3f;
int cnt=0;

struct node {
        int v;
        int w;
};


class MST {
public:
        int n;
        int e;
        bool vis[maxn] = {false};
        int dis[maxn];
        vector<node> Adj[maxn];

        MST(int N, int E) : n(N), e(E)
        {}

        int prim();
};

/*
 * 使用greater<>
 * pair的优先队列，先按照first升序，再按照second升序
 * first--->dis
 * second--->v
 * */
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > q;
int MST::prim()
{
        int ans=0;
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        dis[1]=0;
        q.push(make_pair(0,1));
        while (!q.empty()&&cnt<n){
                int d=q.top().first;
                int v=q.top().second;
                q.pop();
                if (vis[v]) continue;
                cnt++;
                ans+=d;
                vis[v]=true;
                for (int i = 0; i < Adj[v].size(); i++) {
                        node cur=Adj[v][i];
                        if (cur.w<dis[cur.v]){
                                dis[cur.v]=cur.w;
                                q.push(make_pair(dis[cur.v],cur.v));
                        }
                }
        }
        if (cnt==n){return ans;}
        else return -1;
}


int main()
{
        int n, m;
        scanf("%d %d", &n, &m);
        MST mst(n, m);
        for (int i = 0; i < m; i++) {
                int u, v, w;
                scanf("%d %d %d", &u, &v, &w);
                /* 无向图 */
                mst.Adj[u].push_back(node{v, w});
                mst.Adj[v].push_back(node{u, w});
        }
        int ans=mst.prim();
        if (ans==-1){
                printf("orz\n");
        }else{
                printf("%d\n",ans);
        }
        return 0;
}
