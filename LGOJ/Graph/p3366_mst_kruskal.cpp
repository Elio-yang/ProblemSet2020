//
// Created by ELIO on 2020/12/11.
//

#include <cstdio>
#include <cstdlib>

/*
 * Kruskal的过程：<找边>
 *      1.结构体数组存边，按照权重升序排序
 *      2.枚举所有的边T：
 *              T的两个端点为u v，查找u，v的父亲 f_u f_v
 *              a. f_u==f_v 说明 u v 连通 ，continue
 *              b. f_u!=f_v 说明 u v 属于不同的连通块 合并f_u 和 f_v
 *                      1.ans更新
 *                      2.cnt_edge更新：如果==n-1 就退出
 *     3.判断cnt_edge==n-1 看是否生成了MST
 *
 * 注意：
 *      1.Union-find 的编写，路径合并，查找
 *      2.每次看是否在两个连通块内，是看其父亲，合并也是合并其父亲！！
 *      3.qsort的cmp函数的编写(升序与降序的规则)
 * */
const int maxe=2*100000;
const int maxn=5000+10;
struct edge{
        //u---w-->v
        int u;
        int v;
        int w;
};
int cmp(const void *a,const void *b)
{
        auto e_a=(edge*)a;
        auto e_b=(edge*)b;
        return e_a->w - e_b->w;
}

edge E[maxe];

class MST{
public:
        int n;
        int e;
        int cnt;
        MST(int N,int E):n(N),e(E),cnt(0){}

        int Set[maxn]={0};
        void UF_init(){
                for (int i = 1; i <= n; i++) {
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

int MST::kruskal()
{
        qsort(E,e,sizeof(E[0]),cmp);
        UF_init();
        int ans=0;
        int cnt_e=0;
        for (int i = 0; i < e; i++) {
                edge cur_e=E[i];
                int f_u=find(cur_e.u);
                int f_v=find(cur_e.v);
                if (f_u==f_v) continue;
                /*
                 * !!!注意 是connect f_u 和 f_v
                 * 而不是 connect cur_e.u 和 cur_e.v
                 * 有路径合并！！
                 * */
                connected(f_u,f_v);
                ans+=cur_e.w;
                cnt_e++;
                if (cnt_e==n-1){
                        break;
                }
        }
        if (cnt_e!=n-1){
                return -1;
        }else{
                return ans;
        }

}

int main()
{
        int n,m;
        scanf("%d %d",&n,&m);
        MST mst(n,m);
        for (int i = 0; i < m; i++) {
                int u,v,w;
                scanf("%d %d %d",&u,&v,&w);
                E[i].u=u;
                E[i].v=v;
                E[i].w=w;
        }
        int ans=mst.kruskal();
        if (ans==-1){
                printf("orz\n");
        }else{
                printf("%d\n",ans);
        }
        return 0;
}












