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


struct Queue{
        int size;
        int Front;
        int Rear;
        int *queue;
        explicit Queue(int n):size(0),Front(1),Rear(0){
                queue=new int[n];
        }
        int empty() const{return size==0;}
        int front() const{return queue[Front];}
        void push(int ele){size++;Rear++;queue[Rear]=ele;}
        void pop(){size--;Front++;}

};

/*图的顶点 v*/
struct vertex {
        data_t data;
        data_t weight;
        vertex *next;

        vertex(int d, int w);
};

vertex::vertex(int d, int w): data(d), weight(w),next(nullptr){}

/*图类*/
struct Graph {
        int n;
        int e;
        int table_size;
        vertex **list;
        Graph(int size,int v_n,int e_n);
        bool spfa(int s);

};

Graph::Graph(int size,int v_n,int e_n) : table_size(size),n(v_n),e(e_n){
        list = new vertex* [table_size + 10];
        for (int i = 0; i < table_size + 10; i++) {
                list [i] = new vertex(i, 0);
        }
}

int d[max_size];
int num[max_size];
bool inq[max_size];


bool Graph::spfa(int s)
{
        memset(inq, false,sizeof(inq));
        memset(num,0,sizeof(num));
        memset(d,1,sizeof(d));
        Queue Q(n+10);
        Q.push(s);
        inq[s]=true;
        num[s]++;
        d[s]=0;
        while (!Q.empty()){
                int u=Q.front();
                Q.pop();
                inq[u]= false;
                vertex* w = list [u]->next;
                while (w != nullptr) {
                       int dis=w->weight;
                       int v=w->data;
                       if(d[u]+dis<d[v]) {
                               d[v] = d[u] + dis;
                               if(!inq[v]){
                                       Q.push(v);
                                       inq[v]= true;
                                       num[v]++;
                                       if(num[v]>=n){return false;}
                               }
                       }
                        w = w->next;
                }


        }
        return true;
}

int main() {
        int n, e, m;
        while (scanf("%d %d %d", &n, &e, &m) != EOF) {
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
                bool f;
                for(int i=0;i<m;i++){
                        int x,y;
                        scanf("%d %d",&x,&y);
                        f=G->spfa(x);
                        if(!f){continue;}
                        else{
                                if(d[y]==inf){
                                        printf("none\n");
                                }else{
                                        printf("%d\n",d[y]);
                                }
                        }
                }
                if(!f){
                        printf("negative circle\n");
                }
        }

        return 0;
}
