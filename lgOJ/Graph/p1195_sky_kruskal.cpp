#include <cstdio>
#include <cstdlib>
/*
 * N个顶点的多连通块图，要生成k棵MST 判断是否可能？
 * 假设有x个连通块，每个连通块的顶点数未n_1,n_2,...,n_x
 * 则每个连通块所需要的边数为：n_1-1,n_2-1,...,n_x-1
 * 故总的边数 （n_1+n_2+...+n_k）- k
 * 所以 N-（总边数）= k 就说明生成了k棵连通子树
 *
 * Kruskal 不停地计算，每次tmp--;tmp初始化为N
 *
 *
 * 误区：
 *      是不是需要两个并查集，一个在初始化时判断有几个连通块，另一个则针对每个连通块运用kruskal
 *      答案：不用
 *
 *      取出一条边 因为这条边地两个顶点 一定是在一个图（连通块）里的，都不用判断，只要做kruskal就OK
 * */
using namespace std;
const int maxe = 10000 + 5;
const int maxn = 1000 + 5;
int G[maxn][maxn];
struct edge {
        int u;
        int v;
        int w;
};
edge E[maxe];
struct P{
        int num;
        int id;
        int cost;
};
P father[maxn];

int cmp(const void *a, const void *b)
{
        return ((edge *) a)->w - ((edge *) b)->w;
}

class Sky{
public:
        int n;
        int m;
        int k;
        int cnt_s;
        int Set[maxn]={0};
        Sky(int N,int M,int K):n(N),m(M),k(K),cnt_s(N){}

        void init(){
                for (int i = 1; i <=n ; i++) {
                        Set[i]=i;
                }
        }
        void connected(int x,int y){
                Set[y]=x;
        }
        int find(int x){
                // 路径合并
                if (Set[x]==x){
                        return Set[x]=x;
                }else{
                        return Set[x]=find(Set[x]);
                }
        }
        int kruskal();
};

int Sky::kruskal()
{
        init();
        int tmp=n;
        //if (tmp<k){return -1;}
        int ans=0;
        for (int i = 0; i < m; i++) {
                int f_u=find(E[i].u);
                int f_v=find(E[i].v);
                if (f_u!=f_v){
                        connected(f_u,f_v);
                        ans+=E[i].w;
                        tmp--;
                        /* 注意这个判断条件！！*/
                        if (tmp==k){break;}
                }else{
                        continue;
                }
        }
        if (tmp==k){return ans;}
        else return -1;
}

int main()
{
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        Sky S(n,m,k);

        for (int i = 0; i < m; i++) {
                int u,v,w;
                scanf("%d %d %d",&u,&v,&w);
                E[i]={u,v,w};
        }
        qsort(E,m,sizeof(E[0]),cmp);
        int ans=S.kruskal();
        if (ans==-1){
                printf("No Answer\n");
        }else{
                printf("%d",ans);
        }
        return 0;
}

