#include <cstdio>
#include <cstring>
#include <climits>
/*key 的类型*/
#define data_t int

#define max_size 20010
#define inf 16843009
int dist [max_size];
int path [max_size];
bool vis [max_size] = {false};
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
        node* *list;
        Graph(int size);
        int find_min_dis_v();
        void Dijkstra(int s);
};

Graph::Graph(int size) : table_size(size) {
        list = new node* [table_size + 10];
        for (int i = 0; i < table_size + 10; i++) {
                list [i] = new node;
                list [i]->data = i;
                list [i]->weight = 0;
                list [i]->next = nullptr;
        }/*都用头插法*/
}
int Graph::find_min_dis_v() {
        int min_v = INT_MAX;
        int index = 0;
        for (int i = 0; i < table_size + 10; i++) {
                if (min_v > dist [i] && !vis [i]) {
                        min_v = dist [i];
                        index = i;
                }
        }
        return index;
}
void Graph::Dijkstra(int s) {
        dist [s] = 0;
        int v_i = 0;
        for (int i = 0; i < table_size; i++) {
                v_i = find_min_dis_v();
                vis [v_i] = true;
                node* w = list [v_i]->next;
                while (w != nullptr) {
                        if (!vis [w->data]) {
                                if (dist [w->data] > dist [v_i] + w->weight) {
                                        dist [w->data] = dist [v_i] + w->weight;
                                        path [w->data] = v_i;
                                }
                        }
                        w = w->next;
                }
        }
}
int main() {
        memset(dist, 1, sizeof(dist));
        memset(path, -1, sizeof(path));
        int n, e;//顶点数 边数
        scanf("%d %d", &n, &e);
        auto G = new Graph(n + 10);
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
                auto tmp =G->list [v_1]->next;
                G->list [v_1]->next = v_i;
                v_i->next = tmp;
        }
        G->Dijkstra(0);
        for (int i = 0; i < n; i++) {
                if (dist [i] != inf && dist [i] != 0) {
                        printf("%d ", dist [i]);
                }
        }
        return 0;
}
