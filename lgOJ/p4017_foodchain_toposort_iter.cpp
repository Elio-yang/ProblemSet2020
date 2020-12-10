/*
 这道题求最长食物链的条数：即从最高捕食者到生产者（不捕食）的路径条数
 首先，拓扑排序是必要的，如何计算路径？？
     2
  / | \
 1——3--5
    \ /
     4

 5-->2-->1
 5-->3-->2-->1
 5-->3-->1
 5-->4-->3-->1
 5-->4-->3-->2-->1

 f[5]=1
 f[4]+=f[5] ==1

 f[3]+=f[4]
 f[3]+=f[5]
 f[3]=1+1=2

 f[2]+=f[3]
 f[2]+=f[5]
 f[2]=3

 f[1]+=f[2]
 f[1]+=f[3]
 f[1]=5

 因此 假设 i 被 K_j 捕食，从而
 f[i]=f[i]+f[K_1]+f[K_2]+...+f[K_j]
     =f[i]+Sum_j f[K_j]

 首先将最高捕食者的f都初始化为1 ，别的都初始化为0
 结果的路径在生产者处计算（deg_in=deg_out==0)
 */

#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int maxn=5005;
const int inf=0x3f3f3f3f;
const int mod=80112002;

int G[maxn][maxn];
int path[maxn];
int deg_in[maxn];//入度
int deg_out[maxn];//出度
int ans;

class foodchain{
public:
        int n;
        int e;
        foodchain(int N,int E):n(N),e(E){}
        void tsort();
};

void foodchain::tsort()
{
        queue<int> q;
        for (int i=1;i<=n;i++){
                if (deg_in[i]==0){
                     q.push(i);
                     path[i]=1;
                }
        }

        while (!q.empty()){
                int u=q.front();
                q.pop();
                for (int i = 1; i <=n ; i++) {
                        if (G[u][i]!=inf){
                                path[i]+=path[u];
                                path[i]%=mod;
                                deg_in[i]--;
                                if (deg_in[i]==0){
                                        if (deg_out[i]==0){
                                                /*无进无处，到他的路径数目就是答案*/
                                                ans+=path[i];
                                                ans%=mod;
                                        }
                                        q.push(i);
                                }
                        }
                }
        }
        printf("%d",ans);
}

int main()
{
        int n,m;
        scanf("%d %d",&n,&m);
        foodchain L(n,m);
        memset(G,0x3f,sizeof(G));
        for (int i = 0 ; i <m ; i++) {
                int u,v;
                //v-->u 捕食关系
                scanf("%d %d",&u,&v);
                G[v][u]=1;
                deg_in[u]++;
                deg_out[v]++;
        }
        L.tsort();
        return 0;
}
