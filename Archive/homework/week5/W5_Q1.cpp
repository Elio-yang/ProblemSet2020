//#include <cstdio>
//#include <cstring>
//#include <climits>
//#include <queue>
//#include <stack>
//using namespace std;
///*key 的类型*/
//#define data_t int
//
//#define max_size 20010
//#define inf 16843009
//#define tmp_max 10
//int dist [max_size];
//int path [max_size];
//bool vis [max_size] = {false};
//
///*图的顶点 v*/
//struct vertex {
//        int data;
//        int weight;
//        int cnt;
//        vertex *next;
//
//        vertex(int d, int w);
//};
//vertex::vertex(int d, int w): data(d), weight(w),cnt(0){}
//
//struct Graph {
//        int n;
//        int e;
//        int table_size;
//        /*
//         * 邻接表：
//         * 第一次malloc：list=(struct node**)malloc(sizeof(struct node*)*table_size)
//         * 第二次malloc：list[i]=（struct node*)malloc(sizeof(struct node))
//         * */
//        vertex **list;
//        int graph_matrix[tmp_max][tmp_max];
//        int path_floyd[tmp_max][tmp_max];
//        /*for directional graph*/
//        Graph(int size,int v_n,int e_n);
//        /*for non-directional graph*/
//        void Dijkstra(int a, int *arr, int index) const;
//        int find_min_dis_v(int *arr, int index) const;
//};
//
//Graph::Graph(int size,int v_n,int e_n) : table_size(size),n(v_n),e(e_n){
//        list = new vertex* [table_size];
//        for (int i = 0; i < table_size; i++) {
//                list [i] = new vertex(i, 0);
//                list [i]->next = nullptr;
//        }
//}
//int Graph::find_min_dis_v(int*arr,int index) const {
//        int min_v = INT_MAX;
//        int id = 0;
//        for (int i = 0; i < index; i++) {
//                if(!vis[arr[i]]&&dist[arr[i]]<min_v){
//                        min_v=dist[arr[i]];
//                        id=arr[i];
//                }
//        }
//        return id;
//}
//void Graph::Dijkstra(int s,int *arr,int index) const {
//        dist [s] = 0;
//        list[s]->cnt=0;
//        int v_i;
//        for (int i = 0; i < table_size; i++) {
//                int cnt=0;
//                v_i = find_min_dis_v(arr,index);
//                vis [v_i] = true;
//                vertex* w = list [v_i]->next;
//                while (w != nullptr) {
//                        if (!vis [w->data]&&dist [w->data] >= dist [v_i] + w->weight) {
//                                if(dist [w->data] > dist [v_i] + w->weight){
//                                        dist [w->data] = dist [v_i] + w->weight;
//                                        path [w->data] = v_i;
//                                        w->cnt=list[v_i]->cnt+1;
//                                }else if(dist [w->data] == dist [v_i] + w->weight){
//                                        if(w->cnt > list[v_i]->cnt+1){
//                                                path [w->data] = v_i;
//                                                w->cnt=list[v_i]->cnt+1;
//                                        }
//                                }
//                                path [w->data] = v_i;
//                        }
//                        w = w->next;
//                }
//        }
//}
//
//int main() {
//        memset(dist, 1, sizeof(dist));
//        memset(path, -1, sizeof(path));
//        int n, e;//顶点数 边数
//        scanf("%d %d", &n, &e);
//        auto G = new Graph(n + 10,n,e);
//        int tmp[2010];
//        int index=0;
//        for (int i = 0; i < e; i++) {
//                int v_1, v_2, w_i;
//                /*
//                  edge: v_1 --> v_2
//                  list[v_1]里加上v_2
//                  list[v_i] 节点i 的所有邻接
//                */
//                scanf("%d %d %d", &v_1, &v_2, &w_i);
//                tmp[index]=v_1;
//                index++;
//                tmp[index]=v_2;
//                index++;
//                /*创建v2顶点*/
//                auto v_i = new vertex(v_2, w_i);
//                auto tmp =G->list [v_1]->next;
//                G->list [v_1]->next = v_i;
//                v_i->next = tmp;
//
//        }
//        G->Dijkstra(0,tmp,index);
//        for (int i = 0; i < n; i++) {
//                if (dist[i] != inf && dist[i] != 0) {
//                        printf("%d ", dist[i]);
//                }
//        }
//        return 0;
//}
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
/*key 的类型*/
#define max_size 20010
#define inf 16843009
#define tmp_max 10
int dist [max_size];
int path [max_size];
bool vis [max_size] = {false};

/*图的顶点 v*/
struct vertex {
        int data;
        int weight;
        int cnt;
        vertex *next{};

        vertex(int d, int w);
};
vertex::vertex(int d, int w): data(d), weight(w),cnt(0),next(nullptr){}

struct Graph {
        int n;
        int e;
        int table_size;
        vertex **list;
        Graph(int size,int v_n,int e_n);
        void Dijkstra(int s) const;
        int find_min_dis_v() const;
};
Graph::Graph(int size,int v_n,int e_n) : table_size(size),n(v_n),e(e_n){
        list = new vertex* [table_size];
        for (int i = 0; i < table_size; i++) {
                list [i] = new vertex(i, 0);
        }
}
int Graph::find_min_dis_v() const {
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
void Graph::Dijkstra(int s) const {
        dist [s] = 0;
        int v_i = 0;
        for (int i = 0; i < table_size; i++) {
                v_i = find_min_dis_v();
                vis [v_i] = true;
                vertex* w = list [v_i]->next;
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
        auto G = new Graph(n + 10,n,e);
        for (int i = 0; i < e; i++) {
                int v_1, v_2, w_i;
                scanf("%d %d %d", &v_1, &v_2, &w_i);
                /*创建v2顶点*/
                auto v_i = new vertex(v_2, w_i);
                auto tmp =G->list [v_1]->next;
                G->list [v_1]->next = v_i;
                v_i->next = tmp;

        }
        G->Dijkstra(0);
        for (int i = 0; i < n; i++) {
                if (dist[i] != inf && dist[i] != 0) {
                        printf("%d ", dist[i]);
                }
        }
        return 0;
}
