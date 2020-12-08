/*
 * ELIO YANG
 * JLU
 * 2020/12/07
 *
 * provides basic graph structure & algorithms:
 * Build :
 *          Adj table
 * Traversal:
 *          bfs
 *          dfs
 * AOV&AOE:
 *          topological sorting
 *          find critical path
 *
 * Shortest path:
 *                  dijkstra
 *                  floyd
 *                  bellman-ford
 *                  spfa
 * Minimal spanning :
 *                  prim
 *                  kruskal
 **/
#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;
const int max_n = 1000;
const int inf = 0x3f3f3f3f;

struct node {
        int v;
        int w;
        node *next;

        node(int V, int W) : v(V), w(W), next(nullptr)
        {}
};

struct degree {
        int in;
        int out;

        degree() : in(0), out(0)
        {}

        void minus_in()
        { --in; }

        void add_out()
        { ++out; }

        void add_in()
        { ++in; }
};

struct Pair {
        int f;
        int s;
};
Pair critical_path[max_n];

pair<int, int> critical[max_n];

class Graph {
public:
        int n;//顶点数
        int e;//边数
        bool vis[max_n] = {false};
        node *D_adj[max_n]{};
        node *uD_adj[max_n]{};

        //边的集合，包含入度，出度
        degree set_edge[max_n];

        //存放拓扑序列，AOE
        stack<int> topo_order;

        //顶点活动的最早开始时间（最长路径）
        int ve[max_n];

        //顶点活动的最晚开始时间
        int vl[max_n];

        //关键活动的个数
        int cnt;

        //Dijkstra算法的D数组 与 path数组
        int D_dij[max_n];
        int p_dij[max_n];

        //构造函数
        Graph(int N, int E, int flag) : n(N), e(E), cnt(0)
        {
                for (int i = 0; i < n; i++) {
                        D_adj[i] = new node(i, 0);
                        uD_adj[i] = new node(i, 0);
                }
                if (flag == 1) {

                        for (int i = 0; i < e; i++) {
                                int u, v, w;
                                scanf("%d %d %d", &u, &v, &w);
                                //u-->v
                                node *P = new node(v, w);
                                P->next = D_adj[u]->next;
                                D_adj[u]->next = P;
                                set_edge[u].add_out();
                                set_edge[v].add_in();
                        }
                } else {
                        for (int i = 0; i < e; i++) {
                                /*无向图*/
                                int u, v, w;
                                scanf("%d %d %d", &u, &v, &w);
                                //u-->v
                                node *P = new node(v, w);
                                P->next = D_adj[u]->next;
                                D_adj[u]->next = P;
                                //v-->u
                                node *P2 = new node(u, w);
                                P2->next = uD_adj[v]->next;
                                uD_adj[v]->next = P2;
                        }
                }
        }

        //广度优先搜索
        void bfs(int v)
        {
                queue<int> q;
                vis[v] = true;
                //操作

                /*1.访问起点，入队*/
                q.push(v);
                /*2.队列非空则循环*/
                while (!q.empty()) {
                        int u = q.front();
                        q.pop();
                        /*
                         3.从队头取出一个顶点，检测其每个 未被访问的 邻接顶点w
                                a. 访问w （操作w）
                                b. 标记已经访问
                                c. w 入队
                         */
                        node *tmp = D_adj[u]->next;
                        while (tmp != nullptr) {
                                //u--->tmp
                                if (!vis[tmp->v]) {
                                        vis[tmp->v] = true;
                                        //操作
                                        q.push(tmp->v);
                                }
                                tmp = tmp->next;
                        }
                        /*4. 重复 <2.>*/
                }
                /*
                 如果要输出bfs的层号，结构体内多加一个成员layer
                 队列里也应该放结构体 queue<node> Q;
                 然后传入起点s 做成node变量
                 node start{s,0}
                 在遍历tmp的邻接时，有
                 (tmp->next)->layer = tmp->layer + 1;
                 (tmp->next!=nullptr)
                 */
        }

        void trave_bfs()
        {
                memset(vis, 0, sizeof(vis));
                for (int i = 0; i < n; i++) {
                        if (!vis[i]) {
                                bfs(i);
                        }
                }
        }

        //深度优先搜索
        void dfs(int v)
        {
                /*
                 1. 访问该顶点
                 */
                vis[v] = true;
                //对v的操作在此处进行

                /*
                 2.访问该顶点的为被访问的邻接顶点
                 */
                node *tmp = D_adj[v]->next;
                while (tmp != nullptr) {
                        if (!vis[tmp->v]) {
                                /*
                                 3.递归
                                 */
                                dfs(tmp->v);
                        }
                        tmp = tmp->next;
                }
        }

        //迭代版深度优先搜索
        void dfs_it(int s)
        {
                stack<int> stk;
                /*1.源点入栈*/
                stk.push(s);
                /*2.栈非空，则循环*/
                while (!stk.empty()) {
                        int v = stk.top();
                        stk.pop();
                        /*
                         3.弹出栈顶元素v 如果该顶点未被访问则
                                a.访问（操作）v，并标记为已经访问
                                b.将v未被访问的邻接顶点入栈
                         4.重复 <2.>
                         */
                        if (!vis[v]) {
                                vis[v] = true;
                                //操作
                                node *tmp = D_adj[v]->next;
                                while (tmp != nullptr) {
                                        if (!vis[tmp->v]) {
                                                stk.push(tmp->v);
                                                tmp = tmp->next;
                                        }
                                }
                        }
                }
        }

        void trave_dfs()
        {
                memset(vis, 0, sizeof(vis));
                /*考虑有不连通的情况需要枚举所有顶点*/
                for (int i = 0; i < n; i++) {
                        if (!vis[i]) {
                                dfs(i);
                        }
                }
        }

        bool topological_sort()
        {
                //int cnt=0;
                queue<int> q;
                /*1.入度为0的顶点入队*/
                for (int i = 0; i < n; i++) {
                        if (set_edge[i].in == 0) {
                                q.push(i);
                        }
                }
                /*2.队列非空则*/
                while (!q.empty()) {
                        /*3.从队头取出一个顶点*/
                        int u = q.front();
                        q.pop();
                        topo_order.push(u);
                        /*
                         4.删除该顶点，以及与这个顶点邻接的顶点的一条边
                                a.若删除边后，邻接顶点入度为0 则入队
                         */
                        node *tmp = D_adj[u]->next;
                        while (tmp != nullptr) {
                                //u-->tmp->v
                                set_edge[tmp->v].minus_in();
                                if (set_edge[tmp->v].in == 0) {
                                        q.push(tmp->v);
                                }

                                /*
                                 针对AOE的critical path算法部分:

                                 从源点开始，从左往右计算ve
                                        i--->j
                                 ve[0]=0
                                 ve[j]= max_i{ ve[i] + weight<i,j> }

                                 采取逐次更新，最后得到的必然是最大值
                                */
                                if (ve[u] + tmp->v > ve[tmp->v]) {
                                        ve[tmp->v] = ve[u] + tmp->v;
                                }

                                tmp = tmp->next;
                        }
                        /*5.加入拓扑序列的顶点数增加（u）(不必要)*/
                        //cnt++;

                        /*6. 重复 <2.>*/

                }

                /*7.若拓扑序列的顶点数不等于顶点数，则说明有环，算法终止*/
                if (topo_order.size() == n) {
                        return true;
                } else {
                        //有环
                        return false;
                }

                /*
                 ps:
                 如果要求有多个入度为0的顶点，选择编号小的顶点，
                 那么把queue改成priority_queue,保持队首的元素，
                 始终是队列里最小的元素即可！

                 */
        }

        int Critical_path()
        {
                memset(ve, 0, sizeof(ve));
                if (!topological_sort()) {
                        printf("exists circle!\n");
                        return -1;
                }
                /*
                 初始化vl数组
                 vl[n-1]=ve[n-1]
                 */
                for (int i = 0; i < n; i++) {
                        vl[i] = ve[n - 1];
                }
                /*
                 按照拓扑序列的逆序来计算vl
                        j--->k
                 vl[n-1]=ve[n-1]
                 vl[j]=min_i { vl[k]-weight<j,k>}
                 自右往左进行计算
                 */
                while (!topo_order.empty()) {
                        int u = topo_order.top();
                        topo_order.pop();
                        node *tmp = D_adj[u]->next;
                        while (tmp != nullptr) {
                                //u--->tmp->v
                                if (vl[tmp->v] - tmp->w < vl[u]) {
                                        vl[u] = vl[tmp->v] - tmp->w;
                                }
                                tmp = tmp->next;
                        }
                }

                /*
                 判断关键活动
                        j----a_i---->k
                 e[i]=ve[j]
                 l[i]=vl[k]-weight<i,k>

                 遍历所有的边来求解

                 if(e[i]==l[i]){
                        j--->k is critical activity!
                 }
                 */
                for (int i = 0; i < n; i++) {
                        node *tmp = D_adj[i]->next;
                        while (tmp != nullptr) {
                                //i--->tmp->v
                                int est = ve[i];//e[i]
                                int lst = vl[tmp->v] - tmp->w;//l[i]


                                if (est == lst) {
                                        critical[cnt++] = {i, tmp->v};
                                        printf("%d -> %d\n", i, tmp->v);
                                }
                                tmp = tmp->next;
                        }
                }
                return ve[n - 1];
        }

        //单源Dijkstra算法
        /*
                D_i表示源点到i的最短距离
         1.初始化 D_s=0;D_i=inf
         2.在vis[i]=false 的顶点中，选择Di最小的v 访问v(一开始这个v就是源点)
         3.以v为顶点，访问v的所有邻接顶点w，更新D_w

         */
        int Dijkstra(int s)
        {
                memset(vis, 0, sizeof(vis));
                memset(D_dij, 0x3f, sizeof(D_dij));
                memset(p_dij, -1, sizeof(p_dij));

                //初始化
                D_dij[s] = 0;
                vis[s] = true;


                //u是即将要访问的顶点
                int u = s;
                //tmp是u的邻接顶点
                node *tmp = D_adj[u]->next;
                for (int i = 0; i < n; i++) {
                        while (tmp != nullptr) {
                                //u---> tmp->v
                                if (!vis[tmp->v]&&D_dij[u] + tmp->w < D_dij[tmp->v]) {
                                        D_dij[tmp->v] = D_dij[u] + tmp->w;
                                        p_dij[tmp->v]=u;
                                }
                                tmp = tmp->next;
                        }

                        int min = INT_MAX;
                        int index;
                        for (int j = 0; j < n; j++) {
                                if (!vis[i] && D_dij[i] < min) {
                                        min = D_dij[i];
                                        index = i;
                                }
                        }
                        u = i;
                        vis[u] = true;
                        tmp = D_adj[u]->next;
                }

        }

        void floyd(){

        }
        void bellman_ford(){

        }
        void spfa(){

        }
        int prim(){

        }
        int kruskal(){

        }


};



