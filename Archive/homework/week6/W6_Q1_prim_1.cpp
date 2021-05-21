#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
const  int inf=0x3f3f3f3f;
const  int maxn =210;

struct Prim{
        int n;
        bool vis[maxn]={false};
        int d[maxn];
        int G[maxn][maxn];
        Prim(int num):n(num){
                memset(d,0x3f,sizeof(d));
                memset(G,0x3f,sizeof(G));
        }
        int prim(){
                d[0]=0;
                int ans=0;
                for (int i = 0; i < n; i++) {
                        int u=-1;
                        int min=inf;
                        for (int j = 0; j < n; j++) {
                                if(!vis[j]&&d[j]<min){
                                        u=j;
                                        min=d[j];
                                }
                        }
                        if(u==-1){
                                return -1;//不连通
                        }
                        vis[u]= true;
                        ans+=d[u];
                        for (int j = 0; j < n; j++) {
                                if(!vis[j]&&G[u][j]!=inf&&G[u][j]<d[j]){
                                        d[j]=G[u][j];
                                }
                        }
                }
                return ans;
        }
};
int main()
{
        int n,e;
        while (scanf("%d %d",&n,&e)!=EOF){
                Prim P(n);
                for (int i = 0; i < e; i++) {
                        int u,v,cost;
                        cin>>u>>v;
                        cin>>cost;
                        P.G[u][v]=cost;
                        P.G[v][u]=cost;
                }
                int ans=P.prim();
                if(ans==-1){
                        cout<<"There is no minimum spanning tree."<<endl;
                }else{
                        cout<<ans<<endl;
                }

        }
        return 0;
}
