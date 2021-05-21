#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn=210;
const int inf=0x3f3f3f3f;
struct vertex{
        int v;
        int cost;
};
struct Prim{
        vector<vertex> adj[maxn];
        int n;
        bool vis[maxn]={false};
        int d[maxn];
        Prim(int num):n(num){
                memset(d,0x3f,sizeof(d));
        }

        int prim()
        {
                d[0]=0;
                int ans=0;
                for (int i = 0; i < n; i++) {
                        int u=-1;
                        int min=inf;
                        for (int j = 0; j < n; j++) {
                                if (!vis[j]&&min>d[j]){
                                        u=j;
                                        min=d[j];
                                }
                        }
                        if(u==-1){return -1;}
                        vis[u]=true;
                        ans+=d[u];
                        for (int j = 0; j < adj[u].size(); j++) {
                                vertex v=adj[u][j];
                                if(!vis[v.v]&&d[v.v]>v.cost){
                                        d[v.v]=v.cost;
                                }
                        }
                }
                return ans;
        }
};
int main()
{
        int n,e;
        cin>>n>>e;
        Prim P(n);
        for (int i = 0; i < e; i++) {
                int u,v,cost;
                cin>>u>>v>>cost;
                P.adj[u].push_back(vertex{v,cost});
                P.adj[v].push_back(vertex{u,cost});
        }
        int ans=P.prim();
        if(ans==-1){
                cout<<"There is no minimum spanning tree."<<endl;
        }else{
                cout<<ans<<endl;
        }
        return 0;
}
