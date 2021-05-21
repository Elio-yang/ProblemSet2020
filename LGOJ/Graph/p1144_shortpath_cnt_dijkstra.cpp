/*
 * Dijkstra堆优化最短路径计数：
 * 注意 第一次访问的时候，不进行相加，只是赋值
 * 只有第二次访问即（vis=true)时说明是在另一条路，从而
 * 要将cnt相加计算结果
 *
 * 使用stl的priority_queue与自定义的优先队列 对于运算符的重载有区别！！
 * */
#include <cstring>
#include <cassert>
#include <cstdio>

using namespace std;
const int maxn=1000005;
const int maxsize=1000005;
const int inf=0x3f3f3f3f;

struct node{
        int w;
        int v;
        /*记得每次要重载这俩比较运算符来实现优先级的判断*/
        bool operator<(const node& b)const{
                return w<b.w;
        }
        bool operator>(const node& b)const{
                return w>b.w;
        }
};
template < typename T>
class vector {
public:
        typedef T * iterator;
        vector()
        {
                _size = 0;
                _buf = new T[1];
                _capacity = 1;
        }

        vector(int s, T const& a)
        {
                if (s > _max_capacity) {
                        s = _max_capacity;
                }
                _size = s;
                _capacity = 1;
                while (_capacity < _size) {
                        _capacity *= 2;
                }
                _buf = new T[_capacity];
                for (size_t i = 0; i < _size; i++) {
                        _buf[i] = a;
                }
        }

        ~vector()
        {
                delete[] _buf;
        }
        size_t size() const
        {
                return _size;
        }

        void push_back(const T& val)
        {
                if (_size < _capacity) {
                        _buf[_size] = val;
                        _size++;
                        return ;
                } else if (_size == _max_capacity) {
                        return ;
                }
                _capacity *= 2;
                if (_capacity >= _max_capacity) {
                        _capacity = _max_capacity;
                }
                T * tmp = new T[_capacity];
                for (size_t i = 0; i < _size; i++) {
                        tmp[i] = _buf[i];
                }
                tmp[_size] = val;
                _size++;
                delete[] _buf;
                _buf = tmp;
        }
        T& operator[](int index)
        {
                assert(index >= 0 && index < _size);
                return _buf[index];
        }
        vector<T>& operator=(const vector<T>& a)
        {
                if (this == &a) {
                        return *this ;
                }
                delete[] _buf;
                _size = a._size;
                _capacity = a._capacity;
                _buf = new T[_capacity];
                for (size_t i = 0; i < _size; i++) {
                        _buf[i] = a._buf[i];
                }
                return *this;
        }

        bool empty() const
        {
                if (_size == 0) {
                        return true;
                }
                return false;
        }
        iterator begin() const
        {
                return _buf;
        }
        iterator end() const
        {
                return _buf + _size;
        }
private:
        size_t  _size;
        size_t  _capacity;
        T*      _buf;
        const size_t _max_capacity = 65536;
};
template<typename T>
class priority_queue{
private:
        //当前的大小
        int size;
        //最大的规模
        int Capcity;
        //堆的存放
        T* Contains;
public:
        //无参构造函数
        priority_queue<T>():size(0),Capcity(maxsize){
                Contains=new T[maxsize + 1];
        }
        void push(T E)
        {
                int i;
                for(i=++size; Contains[i / 2] > E; i>>=1){
                        Contains[i]=Contains[i >> 1];
                }
                Contains[i]=E;
        }

        T top()
        {
                return Contains[1];
        }

        void pop()
        {
                int i,child;
                T last_ele=Contains[size--];
                for(i=1;2*i<=size;i=child){
                        child=i<<1;
                        if (child!=size && Contains[child + 1] < Contains[child]){
                                child++;
                        }
                        if (last_ele > Contains[child]){ Contains[i]=Contains[child];}
                        else break;
                }
                Contains[i]=last_ele;
        }
        bool empty()
        {
                return size==0;
        }
};

vector<node>G[maxn];
int dis[maxn];
int cnt[maxn];
bool vis[maxn]={false};
int m,n;


/*node 可以改成pair*/
void Dijkstra()
{
        priority_queue<node> q;
        memset(dis,0x3f,sizeof(dis));
        dis[1]=0;
        cnt[1]=1;
        q.push(node{0,1});

        while (!q.empty()){
                node tmp=q.top();
                q.pop();
                if (vis[tmp.v])continue;
                vis[tmp.v]= true;
                for (int i = 0; i < G[tmp.v].size(); i++) {
                        node cur=G[tmp.v][i];
                        if (!vis[cur.v]&& dis[cur.v] > dis[tmp.v] + cur.w){
                                dis[cur.v]=dis[tmp.v]+cur.w;
                                cnt[cur.v]=cnt[tmp.v];
                                q.push(node{dis[cur.v],cur.v});
                        }
                        else if (dis[cur.v]==dis[tmp.v]+cur.w){
                                cnt[cur.v]=(cnt[cur.v]+cnt[tmp.v])%100003;
                        }
                }
        }
}
int main()
{
        scanf("%d %d",&n,&m);
        for (int i = 0; i < m; i++) {
                int u,v;
                scanf("%d %d",&u,&v);
                if (u==v)continue;
                G[u].push_back(node{1,v});
                G[v].push_back(node{1,u});
        }
        Dijkstra();
        for(int i = 1; i <=n ; i++) {
                printf("%d\n",cnt[i]);
        }
        return 0;
}