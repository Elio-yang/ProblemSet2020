#include <cstdio>
#include <cstdlib>

/*
 * 规划一条从 ss 至 tt 的路线，使得经过道路的 w的最大值 最小
 * 即： 每条从s-->t的道路都有一个W_max_i
 * 求 min_i{ W_max_i }
 *
 * kruskal:
 *      按照Kruskal,生成这个图的MST
 *      每次连接两个连通块时，看此时s与t是否连通？
 *      如果连通：因为是按照最小生成树生成所以这个最后连接的边是 "最小的" 最大边
 *      比之前的边都要大，是这条路径里的最大值，同时，这是按照MST 在生成，是最小的
 *      ！！！注意怎么转化到Kruskal的！！！
 *
 * kruskal模板：
 *      1.边数组 排序
 *      2.枚举所有的边：
 *              端点u,v，找到u，v的父亲
 *              判断u与v是否连通？
 *              不连通，merge（f_u，f_v），更新ans+=w
 *              判断cnt==n-1 ？break
 *      3.cnt==n-1 return ans
 *        return -1;
 *
 * 并查集模板：
 *      1.初始化
 *      2.合并 路径压缩
 *      3.查找
 * */

using namespace std;
const int maxn = 2 * 10000 + 10;
const int maxv = 10000 + 10;
struct edge {
        int u;
        int v;
        int w;
};
edge E[maxn];

class City {
public:
        int n;
        int m;
        int s;
        int t;
        int Set[maxv] = {0};

        City(int N, int M, int S, int T) : n(N), m(M), s(S), t(T)
        {}

        void init()
        {
                for (int i = 1; i <= n; i++) {
                        Set[i] = i;
                }
        }

        void connected(int x, int y)
        {
                Set[y] = x;
        }

        int find(int x)
        {
                if (Set[x] == x) {
                        return x;
                } else {
                        Set[x] = find(Set[x]);
                        return Set[x];
                }
        }


        void kruskal();
};

int cmp(const void *a, const void *b)
{
        return ((edge *) a)->w - ((edge *) b)->w;
}

void City::kruskal()
{
        qsort(E, m, sizeof(E[0]), cmp);
        init();
        for (int i = 0; i < m; i++) {
                int f_u = find(E[i].u);
                int f_v = find(E[i].v);
                if (f_u != f_v) {
                        connected(f_u, f_v);
                        if (find(s) == find(t)) {
                                printf("%d\n", E[i].w);
                                return;
                        }
                }

        }
}

int main()
{
        int n, m, s, t;
        scanf("%d %d %d %d", &n, &m, &s, &t);
        City G(n, m, s, t);
        for (int i = 0; i < m; i++) {
                int u, v, w;
                scanf("%d %d %d", &u, &v, &w);
                E[i] = {u, v, w};
        }
        G.kruskal();
        return 0;

}