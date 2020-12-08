#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>


using namespace std;
#define maxn  300
const int inf=0x3f3f3f3f;

template<typename T>
class queue{
        static constexpr int Empty=-1;
        int size;
        int Front;
        int Rear;
        T *arr;
public:
        queue<T>():Front(1),Rear(0),size(0){
                arr=new T[maxn];
        }

        void pop(){
                ++Front;
                --size;
        }
        void push(T e){
                arr[++Rear]=e;
                ++size;
        }
        T& front(){
                return arr[Front];
        }
        bool empty(){
                return size==0;
        }
        void clear(){
                Front=1;
                Rear=0;
                size=0;
        }
};
template<typename T>
class stack{
private:
        static constexpr int Empty=-1;
        int _size;
        int Top;
        T *arr;
        int max_size;
public:
        explicit stack<T>(int n): Top(Empty), max_size(n), _size(0){
                arr =new T[n];
                if (arr== nullptr){
                        cerr<<"heap overflow"<<endl;
                        return;
                }
        }
        int empty(){
                return (Top==Empty || _size == 0);
        }
        void push(T d){
                if(Top==max_size-1){
                        cerr<<"stack full error"<<endl;
                        return ;
                }
                arr[++Top]=d;
                ++_size;
        }
        void pop(){
                if(empty()){
                        cerr<<"stack empty error"<<endl;
                        return;
                }
                --Top;
                --_size;

        }
        T top(){
                return arr[Top];
        }
        int size() const{
                return _size;
        }
        void clear(){
                Top=-1;
                _size=0;
        }
};

struct Pair {
        int f;
        int s;
};

int cmp(const void *a,const void *b)
{
        Pair *p_a = (Pair *) a;
        Pair *p_b = (Pair *) b;
        if (p_a->f != p_b->f) {
                return p_a->f - p_b->f;
        } else {
                return p_a->s - p_b->s;
        }
}

struct degree{
        int in;
        int out;
        degree():in(0),out(0){}
        void minus_in(){--in;}
        void add_out(){++out;}
        void add_in(){++in;}
};
degree deg[maxn];

stack<int> topo_order(maxn);
queue<int> q;
Pair key_path[300];

class AOE{
public:
        int n;
        int e;
        int cnt;
        int G[maxn][maxn];
        int ve[maxn];
        int vl[maxn];
        bool flag= true;

        AOE(int N,int E):n(N),e(E),cnt(0){}
        bool topological_sort(){
                int num=0;
                for (int i = 1; i <= n; i++) {
                        if (deg[i].in==0){
                                q.push(i);
                        }
                }
                while (!q.empty()){
                        int v=q.front();
                        q.pop();
                        topo_order.push(v);

                        for (int i = 1; i <= n; i++) {
                                if(G[v][i]!=inf){
                                        deg[i].minus_in();
                                        if (deg[i].in==0){
                                                q.push(i);
                                        }
                                        if (ve[v]+G[v][i]>ve[i]){
                                                ve[i]=ve[v]+G[v][i];
                                        }
                                }
                        }
                        num++;
                }
                if (num!=n){
                        printf("unworkable project\n");
                        flag= false;
                        return false;
                }
                else{

                        return true;
                }
        }
        void CRITICAL_PATH(){
                memset(ve,0,sizeof(ve));
                if (!topological_sort()){
                        return;
                }
                /*不确定n是最后一个汇点，找到最大的ve 才能更新vl*/
                int max=-1;
                for (int i = 1; i <=n ; i++) {
                        if (ve[i]>max){
                                max=ve[i];
                        }
                }
                for (int i = 1; i <= n; i++) {
                        vl[i]=max;
                }
                /*求vl数组*/
                while (!topo_order.empty()){
                        int u=topo_order.top();
                        topo_order.pop();
                        for (int i = 1; i <= n; i++) {
                                if (G[u][i]!=inf){
                                        if (vl[i]-G[u][i]<vl[u]){
                                                vl[u]=vl[i]-G[u][i];
                                        }
                                }
                        }
                }
                for (int i = 1; i <= n; i++) {
                        for (int j = 1; j <= n; j++) {
                                if (G[i][j]!=inf){
                                        int earliest=ve[i];
                                        int latest= vl[j] - G[i][j];
                                        if (earliest == latest){
                                               key_path[cnt++]={i,j};
                                        }
                                }
                        }
                }
                printf("%d\n",max);
        }
};

int main()
{
        int n,e;
        while (scanf("%d %d",&n,&e)!=EOF){
                AOE aoe(n,e);
                memset(aoe.G,inf,sizeof(aoe.G));
                for (int i = 0; i < e; i++) {
                        int u,v,w;
                        scanf("%d %d %d",&u,&v,&w);
                        aoe.G[u][v]=w;
                        deg[u].add_out();
                        deg[v].add_in();
                }
                aoe.CRITICAL_PATH();
                if (aoe.flag) {
                        qsort(key_path, aoe.cnt, sizeof(key_path[0]), cmp);
                        for (int i = 0; i < aoe.cnt; i++) {
                                printf("%d->%d\n", key_path[i].f, key_path[i].s);
                        }
                }
                topo_order.clear();
                q.clear();
                memset(deg,0,sizeof(deg));
                memset(key_path,0,sizeof(key_path));
                /*最后要清除*/
        }
        return 0;
}

/*
4 3
1 2 3
2 3 4
3 4 5
12
1->2
2->3
3->4

3 3
1 2 3
2 3 1
3 1 2
unworkable project

4 3
1 2 3
2 3 4
3 4 5
 */