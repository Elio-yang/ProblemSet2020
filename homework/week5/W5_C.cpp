#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#define max_n 305
using namespace std;
//int mycmp(const void *a,const void *b)
//{
//        return *((int*)a)>*((int*)b);
//}
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
        //void sort(){qsort(queue,size,sizeof(int),mycmp);}
};

struct degree{
        int in;
        int out;
        degree():in(0),out(0){}
        void minus_in(){--in;}
        void add_out(){++out;}
        void add_in(){++in;}
};
degree deg[max_n];

int G[max_n][max_n]={0};
int topo_s[max_n];
void topo_sort(int n)
{
        priority_queue<int,vector<int>,greater<int>> q;
        int cnt=0;
        for(int i=0;i<n;i++){
                if(deg[i].in==0){q.push(i);}
        }
        while (!q.empty()){
                int v_i=q.top();
                q.pop();
                topo_s[cnt++]=v_i;
                for(int i=0;i<n;i++){
                        if(G[v_i][i]!=0){
                                deg[i].minus_in();
                                if(deg[i].in==0){
                                        q.push(i);
                                }
                        }
                }
        }
}

int main()
{
        int n,e;
        scanf("%d %d",&n,&e);
        for (int i = 0; i < e; i++) {
                int x,y;
                scanf("%d %d",&x,&y);
                G[x][y]=1;
                deg[x].add_out();
                deg[y].add_in();
        }
        topo_sort(n);
        for (int i=0;i<n;i++){
                printf("%d ",topo_s[i]);
        }
        return 0;
}