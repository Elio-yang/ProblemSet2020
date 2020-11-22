#include <cstdio>
#include <cstring>
#include <climits>
/*key 的类型*/
#define data_t int

/*哈希表的最小大小*/
#define max_size 20010
#define inf 16843009
int dist[max_size];
int path[max_size];
bool vis[max_size] = {false};
struct node {
        data_t data;
        data_t weight;
        struct node *next;
};
struct Graph {
        int table_size;
        /*
         * 指针数组：
         * 第一次malloc：H->list=(struct node**)malloc(sizeof(struct node*)*H->table_size)
         * 第二次malloc：H->list[i]=（struct node*)malloc(sizeof(struct node))
         * */
        node **list;

};

struct Graph *init_graph(int table_size)
{
        auto Adj = new Graph;
        Adj->table_size = table_size;
        Adj->list = new node *[Adj->table_size];
        for (int i = 0; i < table_size; i++) {
                Adj->list[i] = new node;
                Adj->list[i]->data = i;
                Adj->list[i]->weight = 0;
                Adj->list[i]->next = nullptr;
        }
        return Adj;
}

int find_min_dis_v(int n)
{
        int min_v = INT_MAX;
        int index = 0;
        for (int i = 0; i < n; i++) {
                if (min_v > dist[i] && !vis[i]) {
                        min_v = dist[i];
                        index = i;
                }
        }
        return index;
}

void Dijkstra(Graph *Adj, int s, int n)
{
        dist[s] = 0;
        int v_i = 0;
        for (int i = 0; i < n; i++) {
                v_i = find_min_dis_v(n);
                vis[v_i] = true;
                node *w = Adj->list[v_i]->next;
                while (w != nullptr) {
                        if (!vis[w->data]) {
                                if (dist[w->data] > dist[v_i] + w->weight) {
                                        dist[w->data] = dist[v_i] + w->weight;
                                        path[w->data] = v_i;
                                }
                        }
                        w = w->next;
                }
        }
}

int main()
{
        memset(dist, 1, sizeof(dist));
        memset(path, -1, sizeof(path));
        int n, e;//顶点数 边数
        scanf("%d %d", &n, &e);
        Graph *Adj = init_graph(n + 10);
        for (int i = 0; i < e; i++) {
                int v_1, v_2, w_i;
                /* edge: v_1 --> v_2
                 * Adj->list[v_1]里加上v_2
                 * Adj->list[v_i] 节点i 的所有邻接
                 */
                scanf("%d %d %d", &v_1, &v_2, &w_i);
                auto v_i = new node;
                v_i->data = v_2;
                v_i->weight = w_i;
                auto tmp = Adj->list[v_1]->next;
                Adj->list[v_1]->next = v_i;
                v_i->next = tmp;
        }
        Dijkstra(Adj, 0, n);
        for (int i = 0; i < n; i++) {
                if (dist[i] != inf && dist[i] != 0) {
                        printf("%d ", dist[i]);
                }
        }
        return 0;

}
