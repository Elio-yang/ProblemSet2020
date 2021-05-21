#include <cstdio>
#include <vector>
const int maxn =100010;
using namespace std;
int Max=-1;
int ans[maxn];
class Graph{
public:
        int n;
        int e;
        bool vis[maxn]={false};
        vector<int> Adj[maxn];
        Graph(int N,int E):n(N),e(E){}
        void dfs(int s,int max);
        void tra();
};
void Graph::dfs(int s,int max)
{
//        if (Max<s){
//                Max=s;
//        }
//        vis[s]= true;
//        for (int i = 0; i < Adj[s].size(); i++) {
//                if (!vis[Adj[s][i]]){
//                        dfs(Adj[s][i]);
//                }
//        }
        if (ans[s]){return;}//以及找到s走到的最远的顶点
        ans[s]=max;
        for (int i = 0; i < Adj[s].size(); i++) {
                dfs(Adj[s][i],max);
        }
}

void Graph::tra()
{
//        for (int i = 1; i <= n; i++) {
//                dfs(i);
//                memset(vis,0,sizeof(vis));
//                ans[i]=Max;
//                Max=-1;
//                直接每个点dfs可能超时(几乎必定超时)
//        }
        for (int i = n; i >=0 ; i--) {
                dfs(i,i);
                /*！！反着来，都是最大的*/
        }
}

int main()
{
        int n,m;
        scanf("%d %d",&n,&m);
        Graph G(n,m);
        for (int i = 0; i < m; i++) {
                //u-->v
                int u,v;
                scanf("%d %d",&u,&v);
               // G.Adj[u].push_back(v);

                //考虑反向建立图
                //v-->u
                G.Adj[v].push_back(u);
        }
        G.tra();
        for (int i = 1; i <=n ; i++) {
                printf("%d ",ans[i]);
        }
        return 0;
}
