/*
 * 权值为1的最短路径计数
 * 1.bfs:
 *      bfs在权值为1的情况下能保证最短路径
 *      注意几点：
 *              何时标记:入队时即标记，考虑到别的顶点可能指向这个顶点
 *                      如果在出队时标记，会造成错误
 *              如何确定：dep[x]=dep[cur]+1; 其中cur--->t
 *                      对于节点x：
 *                              1.已经访问：更新depth
 *                              2.都要更新cnt；
 * bfs框架：
 *      1.入队源点 入队就要标记
 *      2.对非空循环:
 *              a.出队队头节点；所有的操作在出队的时候进行
 *              b.遍历所有邻接:
 *                      1.如果未访问（！vis）: 入队节点，标记访问
 * 注意：
 *      1.vis数组的标记 ：全在入队的时候
 *      2.操作，打印等 ： 全在出队的时候
 *      3.访问过的邻接，不再入队（不过此时可以有别的操作）
 *
 * */
#include <cstring>
/*队列ADT*/
#include <cstdio>
#include <vector>

using namespace std;
const int maxn = 1000005;
//const int inf=0x3f3f3f3f;
vector<int> G[maxn];
//int dis[maxn];
int dep[maxn];
int cnt[maxn];
bool vis[maxn] = {false};
int m, n;

template<typename T>
class queue {
        static constexpr int Empty = -1;
        int size;
        int Front;
        int Rear;
        T *arr;
public:
        queue<T>() : Front(1), Rear(0), size(0)
        {
                arr = new T[maxn];
        }

        void pop()
        {
                ++Front;
                --size;
        }

        void push(T e)
        {
                arr[++Rear] = e;
                ++size;
        }

        T &front()
        {
                return arr[Front];
        }

        bool empty()
        {
                return size == 0;
        }

        ~queue<T>()
        {
                delete[]arr;
        }
};

void bfs()
{
        cnt[1] = 1;
        dep[1] = 0;
        queue<int> q;
        q.push(1);
        vis[1] = true;
        while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int i = 0; i < G[cur].size(); i++) {
                        int v = G[cur][i];
                        if (!vis[v]) {
                                vis[v] = true;
                                dep[v] = dep[cur] + 1;
                                q.push(v);
                        }
                        if (dep[v] == dep[cur] + 1) { cnt[v] = (cnt[v] + cnt[cur]) % 100003; }
                }
        }
}

int main()
{
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++) {
                int u, v;
                scanf("%d %d", &u, &v);
                //if (u == v)continue;
                G[u].push_back(v);
                G[v].push_back(u);
        }
        bfs();
        for (int i = 1; i <= n; i++) {
                printf("%d\n", cnt[i]);
        }
        return 0;
}