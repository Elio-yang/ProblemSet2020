#include <cstdio>
#include <cstdlib>
#include <cstring>
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
        /*for directional graph*/
        Graph(int size,int v_n,int e_n);
        void to_string() const;
        void del_edge(int s,int t);
};

Graph::Graph(int size,int v_n,int e_n) : table_size(size),n(v_n),e(e_n){
        list = new vertex* [table_size + 10];
        for (int i = 0; i < table_size + 10; i++) {
                list [i] = new vertex(i, 0);
                list [i]->next = nullptr;
        }
}
void  Graph::to_string() const
{
        for(int i=0;i<n;i++){
                vertex *w=list[i]->next;
                if(w== nullptr){continue;}
                printf("%d:",i);
                while (w!= nullptr){
                        printf("(%d,%d,%d)",i,w->data,w->weight);
                        w=w->next;
                }
                printf("\n");
        }
}

struct id{
        int x;
        int y;
        int w;
};

int mycmy(const void *a, const void *b) {
        int v1 = ((id*)a)->x;
        int v2 = ((id*)b)->x;
        int p1 = ((id*)a)->y;
        int p2 = ((id*)b)->y;
        if (v1 != v2) {
                return v1 - v2;
        }
        else {
                return p1 - p2;
        }
}

void Graph::del_edge(int s,int t)
{
        auto w=list[s];
        while (w->next->data!=t){
                w=w->next;
        }
        auto tmp_p=w->next;
        auto tmp=w->next->next;
        w->next=tmp;
        free(tmp_p);
}

int main() {
        int n, e;//顶点数 边数
        scanf("%d %d", &n, &e);
        auto G = new Graph(n + 10,n,e);
        id data[e];
        memset(data,0,sizeof(data));
        for (int i = 0; i < e; i++) {
                int v_1, v_2, w_i;
                scanf("%d %d %d", &v_1, &v_2, &w_i);
                data[i]={v_1,v_2,w_i};
        }
        qsort(data,e,sizeof(id),mycmy);
        for(int i=0;i<e;i++){
                int v_1=data[i].x;
                int v_2=data[i].y;
                int w_i=data[i].w;
                auto v_i = new vertex(v_2, w_i);
                auto p=G->list[v_1];
                while (p->next!= nullptr){
                        p=p->next;
                }
                auto tmp_p=p->next;
                p->next=v_i;
                v_i->next=tmp_p;
        }
        int k;
        scanf("%d",&k);
        for(int i=0;i<k;i++){
                int x,y;
                scanf("%d %d",&x,&y);
                G->del_edge(x,y);
        }
        G->to_string();
        return 0;
}
