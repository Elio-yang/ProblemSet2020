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
int dist [max_size];
int path [max_size];
bool vis [max_size] = {false};

/*图的顶点 v*/
struct vertex {
        data_t data;
        data_t weight;
        int in_deg;
        int out_deg;
        vertex *next;

        vertex(int d, int w, int in_d=0, int out_d=0);
};

vertex::vertex(int d, int w, int in_d, int out_d): data(d), weight(w), in_deg(in_d), out_deg(out_d){}
/*存放度的数组元素*/
struct degree{
        data_t data;
        int in_deg;
        int out_deg;
        degree(int d,int in_d=0,int out_d=0):data(d),in_deg(in_d),out_deg(out_d){}
        void in_add(){++in_deg;}
        void out_add(){++out_deg;}
        void in_minus(){--in_deg;}
        void out_minus(){--out_deg;}

};
/*度-数组*/
degree** deg_recd;
/*图类*/
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
        Graph(int size,int v_n,int e_n);
        /*for non-directional graph*/
        Graph(int n);
        int find_min_dis_v() const;
        void Dijkstra(int s) const;
        void floyd(int s, int d);
        void dfs() const;
        void DFS(int s) const;
        void bfs() const;
        void BFS(int s) const;
        void t_sort() const;
        void to_string() const;
        void has_path_to(int s,int d) const;
        void dfs_path(int v, int *edge_to) const;
        void prim();
        void kruskal();

};

Graph::Graph(int size,int v_n,int e_n) : table_size(size),n(v_n),e(e_n){
        list = new vertex* [table_size + 10];
        for (int i = 0; i < table_size + 10; i++) {
                list [i] = new vertex(i, 0);
                list [i]->next = nullptr;
        }
}
Graph::Graph(int n)
{
        std::memset(graph_matrix,1,sizeof(graph_matrix));
        int i,j;
        for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                        path_floyd[i][j]=j;
                }
        }

}

void Graph::floyd(int s, int d)
{
        int D[tmp_max][tmp_max];
        for(int i=0;i<tmp_max;i++){
                for(int j=0;j<tmp_max;j++){
                        D[i][j]=graph_matrix[i][j];
                }
        }
        for (int k = 0; k < tmp_max; k++) {
                for (int i = 0; i < tmp_max; i++) {
                        for (int j = 0; j < tmp_max; j++) {
                                if(D[i][j]>D[i][k]+D[k][j]){
                                        D[i][j]=D[i][k]+D[k][j];
                                        path_floyd[i][j]=path_floyd[i][k];
                                }
                        }
                }
        }

        printf("shortest path from %d to %s is %d : ",s,d,D[s][d]);
        int k=path_floyd[s][d];
        printf("%d",s);
        while (k!=d){
                printf(" -> %d",k);
                k=path_floyd[k][d];
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

void show_path(int s,Graph* G)
{
        stack<int>p;
        for(int i=1;i<G->n;i++){
                printf("path %d to %d:",s,i);
                int v=path[i];
                p.push(i);
                p.push(v);
                while (v!=s) {
                        v = path[v];
                        p.push(v);
                }

                while (!p.empty()){
                        printf("%d",p.top());
                        p.pop();
                        if(!p.empty()){
                                printf("->");
                        }
                }
                printf("\n");
        }
}

void Graph::dfs() const
{
        for(int i=0;i<n;i++){
                if(!vis[i]){
                        printf("dfs started from vertex %d\n",i);
                        DFS(i);
                }
        }
}

void Graph::DFS(int s) const
{
        vis[s]= true;
        printf("dfs find vertex: %d  in_deg=%d out_deg=%d\n",s,deg_recd[s]->in_deg,deg_recd[s]->out_deg);
        vertex *w=list[s]->next;
        while (w!= nullptr){
                if(!vis[w->data]){
                        DFS(w->data);
                }
                w=w->next;
        }
}

void Graph::bfs() const
{
        for(int i=0;i<n;i++){
                if(!vis[i]){
                        printf("bfs started from vertex %d\n",i);
                        BFS(i);
                }
        }
}

void Graph::BFS(int s) const
{
        queue<int>Q;
        vis[s]= true;
        Q.push(s);
        while (!Q.empty()){
                int v=Q.front();
                printf("bfs find vertex: %d  in_deg=%d out_deg=%d\n",v,deg_recd[v]->in_deg,deg_recd[v]->out_deg);
                Q.pop();
                vertex *w=list[v]->next;
                while (w!= nullptr){
                        if(!vis[w->data]){
                                vis[w->data]=true;
                                Q.push(w->data);
                        }
                        w=w->next;
                }
        }
}

void Graph::t_sort() const
{


}

void  Graph::to_string() const
{
        printf("to represent vertex v_i using (vertex,in_degree,out_degree)\n");
        printf("those who is adjacent to v_i using (vertex,in_degree,out_degree,weight_to_v_i)\n");
        for(int i=0;i<n;i++){
                printf("(%d %d %d) adjacent to:",list[i]->data,list[i]->in_deg,list[i]->out_deg);
                vertex *w=list[i]->next;;
                while (w!= nullptr){
                        printf("(%d %d %d %d)",w->data,w->in_deg,w->out_deg,w->weight);
                        w=w->next;
                        if(w){
                                printf("--->");
                        }
                }
                printf("\n");
        }
}

void Graph::dfs_path(int v, int *edge_to) const
{
        vis[v]= true;
        vertex *w=list[v]->next;
        while (w!= nullptr){
                if(!vis[w->data]){
                        edge_to[w->data]=v;
                        dfs_path(w->data,edge_to);
                }
                w=w->next;
        }

}
void Graph::has_path_to(int s,int d) const
{
        fill(vis,vis+max_size, false);
        auto edge_to=new int[n+10];
        dfs_path(s, edge_to);
        if(vis[d]){
                printf("has path from %d to %d : ",s,d);
        }
        stack<int>p;
        for(int i=d;i!=s;i=edge_to[i]){
                p.push(i);
        }
        p.push(s);
        while (!p.empty()){
                int v_i=p.top();
                p.pop();
                printf("%d",v_i);
                if(!p.empty()){
                        printf("->");
                }
        }
}

void update_deg(Graph *&G)
{
        for(int i=0;i<G->n;i++){
                G->list[i]->in_deg=deg_recd[i]->in_deg;
                G->list[i]->out_deg=deg_recd[i]->out_deg;
                vertex *w=G->list[i]->next;
                while (w!= nullptr){
                        w->in_deg=deg_recd[w->data]->in_deg;
                        w->out_deg=deg_recd[w->data]->out_deg;
                        w=w->next;
                }
        }
}


int main() {
        memset(dist, 1, sizeof(dist));
        memset(path, -1, sizeof(path));
        int n, e;//顶点数 边数
        scanf("%d %d", &n, &e);
        auto G = new Graph(n + 10,n,e);
        deg_recd=new degree*[n];
        for(int i=0;i<n;i++){
                deg_recd[i]=new degree(i);
        }
        for (int i = 0; i < e; i++) {
                int v_1, v_2, w_i;
                /*
                  edge: v_1 --> v_2
                  list[v_1]里加上v_2
                  list[v_i] 节点i 的所有邻接
                */
                scanf("%d %d %d", &v_1, &v_2, &w_i);
                /*创建v2顶点*/
                auto v_i = new vertex(v_2, w_i);
                auto tmp =G->list [v_1]->next;
                G->list [v_1]->next = v_i;
                v_i->next = tmp;

                deg_recd[v_2]->in_add();
                deg_recd[v_1]->out_add();

        }
        update_deg(G);
        printf("table created!\n");
        auto G_2=new Graph(n);
        G->Dijkstra(0);
        printf("minimal path_len for vertex v_i:\n");
        for (int i = 0; i < n; i++) {
                if (dist [i] != inf && dist [i] != 0) {
                        printf("0->%d : %d ",i, dist [i]);
                }
                if(i==n-1){
                        printf("\n");
                }
        }
        printf("****************************************************************\n");
        show_path(0,G);
        printf("****************************************************************\n");
        fill(vis,vis+max_size, false);
        G->dfs();
        printf("****************************************************************\n");
        fill(vis,vis+max_size, false);
        G->bfs();
        printf("****************************************************************\n");
        G->to_string();
        printf("****************************************************************\n");
        G->has_path_to(0,3);
        printf("****************************************************************\n");
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        scanf("%d",&(G_2->graph_matrix[i][j]));
                }
        }
        G_2->floyd(0,3);
        return 0;
}
