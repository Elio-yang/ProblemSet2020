#include <cstdio>

const int maxn=10010;
struct edge{
        int vi;
        int wi;
        edge* next;
        edge(int v,int w):vi(v),wi(w),next(nullptr){}
};

struct recd{
        int sum;
        int max_edge;
        int p_edge;
        recd(int s,int m,int p):sum(s),max_edge(m),p_edge(p){}
};

struct Graph{
        int n,e;
        edge* Adj[maxn];
        recd ans;
        Graph(int num,int m):n(num),e(m){
                for (int i = 0; i < n; i++) {
                        Adj[i]=new edge(i,0);
                }
        }

};