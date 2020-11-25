#include <cstdio>
#include <cstring>
#include <climits>
#include <queue>
#include <stack>

using namespace std;
/*key 的类型*/
#define data_t int

#define max_size 20010
#define inf 16843009
#define tmp_max 10
int dist[max_size];
int path[max_size];
bool vis[max_size] = {false};

/*图的顶点 v*/
struct vertex {
        data_t data;
        data_t weight;
        int cnt;
        vertex *next;

        vertex(int d, int w);
};

vertex::vertex(int d, int w) : data(d), weight(w), cnt(0){}

struct Graph {
        int n;
        int e;
        int table_size;
        /*
         * 邻接表：
         * 第一次malloc：list=(struct node**)malloc(sizeof(struct node*)*table_size)
         * 第二次malloc：list[i]=（struct node*)malloc(sizeof(struct node))
         * */
        vertex **list;
        int graph_matrix[tmp_max][tmp_max];
        int path_floyd[tmp_max][tmp_max];

        /*for directional graph*/
        Graph(int size, int v_n, int e_n);

        /*for non-directional graph*/
        int find_min_dis_v(int *arr, int index) const;

        void Dijkstra(int a, int *arr, int index) const;
};

Graph::Graph(int size, int v_n, int e_n) : table_size(size), n(v_n), e(e_n)
{
        list = new vertex *[table_size];
        for (int i = 0; i < table_size; i++) {
                list[i] = new vertex(i, 0);
                list[i]->next = nullptr;
        }
}

int Graph::find_min_dis_v(int *arr, int index) const
{
        int min_v = INT_MAX;
        int id = 0;
        for (int i = 0; i < index; i++) {
                if (!vis[arr[i]] && dist[arr[i]] < min_v&&dist[arr[i]]>0) {
                        min_v = dist[arr[i]];
                        id = arr[i];
                }
        }
        return id;
}

void Graph::Dijkstra(int a, int *arr, int index) const
{
        dist[a] = 0;
        list[a]->cnt = 0;
        vertex *p = list[a]->next;
        for (int i = 0; i < n; i++) {
                while (p != nullptr) {
                        int b = p->data;
                        if (!vis[b] && (dist[b] >= dist[a] + p->weight)) {
                                if (dist[b] > dist[a] + p->weight) {
                                        dist[b] = dist[a] + p->weight;
                                        path[b] = a;
                                        list[b]->cnt = list[a]->cnt + 1;
                                }
                                if(dist[b] == dist[a] + p->weight) {
                                        if (list[b]->cnt > list[a]->cnt + 1) {
                                                path[b] = a;
                                                list[b]->cnt = list[a]->cnt + 1;
                                        }
                                }
                        }/*保证节点数最少*/
                        p = p->next;
                }
                a = find_min_dis_v(arr, index);
                vis[a] = true;
                p=list[a]->next;
        }
}

void show_path(int s, Graph *G)
{
        if (path[s] != -1) {
                show_path(path[s], G);
                printf("->");
        }
        printf("%d", s);

}

int main()
{
        memset(dist, 1, sizeof(dist));
        memset(path, -1, sizeof(path));
        int n, e;//顶点数 边数
        scanf("%d %d", &n, &e);
        auto G = new Graph(n + 10, n, e);
        int tmp[2010];
        int index = 0;
        for (int i = 0; i < e; i++) {
                int v_1, v_2, w_i;
                /*
                  edge: v_1 --> v_2
                  list[v_1]里加上v_2
                  list[v_i] 节点i 的所有邻接
                */
                scanf("%d %d %d", &v_1, &v_2, &w_i);
                tmp[index] = v_1;
                index++;
                tmp[index] = v_2;
                index++;
                /*创建v2顶点*/
                auto v_i = new vertex(v_2, w_i);
                auto tmp = G->list[v_1]->next;
                G->list[v_1]->next = v_i;
                v_i->next = tmp;

        }
        G->Dijkstra(0, tmp, index);
        for (int i = 1; i < G->n; i++) {
                if(dist[i]!=inf){
                        show_path(i, G);
                        if(i!=G->n-1){
                                printf("\n");
                        }
                }
        }
        return 0;
}
