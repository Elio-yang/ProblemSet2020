/*
 * priority_queue<T> q
 * 实现小顶堆
 * 支持操作：
 *      1.创建
 *      2.插入
 *      3.删除最小值
 *      4.取顶
 **/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;
const int maxsize=1000010;
const int inf=0x3f3f3f3f;
const int maxn=100010;
int dis[maxn];
bool vis[maxn];
/*
 * T 需要重载比较运算符来实现优先级
 * bool operator<(const T& b)const{return ??}
 * T 需要重载赋值运算符
 * bool operator=(const T& b)const{return ??}
 **/

template<typename T>
class priority_queue{
private:
        //当前的大小
        int size;
        //最大的规模
        int Capcity;
        //堆的存放
        T* eles;
public:
        //无参构造函数
        priority_queue<T>():size(0),Capcity(maxsize){
                eles=new T[maxsize+1];
        }
        void push(T E);
        T top();
        void pop();
        bool empty();
};

template<typename T>
void priority_queue<T>::push(T E)
{
        int i;
        for(i=++size;eles[i/2]> E;i>>=1){
                eles[i]=eles[i>>1];
        }
        eles[i]=E;
}

template<typename T>
T priority_queue<T>::top()
{
        return eles[1];
}

template<typename T>
void priority_queue<T>::pop()
{
        int i,child;
        T last_ele=eles[size--];
        for(i=1;2*i<=size;i=child){
                child=i<<1;
                if (child!=size&&eles[child+1]<eles[child]){
                        child++;
                }
                if (last_ele>eles[child]){eles[i]=eles[child];}
                else break;
        }
        eles[i]=last_ele;
}
template<typename T>
bool priority_queue<T>::empty()
{
        return size==0;
}

struct node{
        int v;
        int w;
        node(int V=0,int W=0):v(V),w(W){}
        bool operator<(const node b) const{
                return w<b.w;
        }
        bool operator>(const node b) const{
                return w>b.w;
        }
};

vector<node> Adj[maxn];
int n,m,s;

void Dijkstra(int S){
        /*堆优化的Dijkstra 主要是每次找最小的dis的v*/
        priority_queue<node> Q;
        dis[S]=0;
        Q.push(node(S,0));

        while (!Q.empty()){
                node tmp = Q.top();
                Q.pop();
                int t_v = tmp.v;
                if (vis[t_v]) continue;
                vis[t_v] = true;
                for (int j = 0; j < Adj[t_v].size(); j++) {
                        int v = Adj[t_v][j].v;
                        if (!vis[v] && dis[t_v] + Adj[t_v][j].w < dis[v]) {
                                dis[v] = dis[t_v] + Adj[t_v][j].w;
                                Q.push(node(v, dis[v]));
                        }
                }
        }
}
int main()
{
        scanf("%d %d %d",&n,&m,&s);
        for (int i = 0; i < m; i++) {
                int u,v,w;
                scanf("%d %d %d",&u,&v,&w);
                node new_node(v,w);
                Adj[u].push_back(new_node);
        }
        memset(dis,0x3f,sizeof(dis));
        Dijkstra(s);
        for (int i = 1; i <=n ; i++) {
                printf("%d ",dis[i]);
        }
        return 0;
}