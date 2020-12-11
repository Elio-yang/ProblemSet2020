#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
const int maxn = 5000+5;
const int maxe=200000+5;
struct UF {
        int n;
        int set [maxn]={0};
        explicit UF(int num):n(num){
                for (int i = 0; i < n; i++) {
                        set[i]=i;
                }
        }
        void merge(int a, int b) {
                set [b] = a;
        }
        int find(int a) {
                if (set [a] == a) {
                        return set[a]=a;
                }
                else {
                        return set[a]=find(set [a]);
                }
        }
};

struct edge{
        int u,v;
        int cost;
}E[maxe];

int cmp(const void *a,const void *b)
{
        int c_a= ((edge*)a)->cost;
        int c_b=((edge*)b)->cost;
        return c_a-c_b;
}

int kruskal(int n,int e)
{
        int ans=0;
        int num_edge=0;
        UF uf_set(n);
        qsort(E,e,sizeof(E[0]),cmp);
        for (int i = 0; i < e; i++) {//注意是循环e次
                int fa_u=uf_set.find(E[i].u);
                int fa_v=uf_set.find(E[i].v);
                if(fa_u!=fa_v){
                        uf_set.merge(fa_u,fa_v);
                        ans+=E[i].cost;
                        num_edge++;
                        if(num_edge==n-1){
                                break;
                        }
                }
        }
        if(num_edge!=n-1){
                return -1;
        }else{
                return ans;
        }
}
int main()
{
        int n,e;
        cin>>n>>e;
        for (int i = 0; i < e; i++) {
                cin>>E[i].u>>E[i].v>>E[i].cost;
        }
        int ans=kruskal(n,e);
        if(ans==-1){
                cout<<"There is no minimum spanning tree."<<endl;
        }else{
                cout<<ans<<endl;

        }
        return 0;
}