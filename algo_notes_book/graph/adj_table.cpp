#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class vertex{
public:
        int w;
        int v;
        vertex(int &v_i, int &w_i): v(v_i), w(w_i){}
};

constexpr int max_v_n=1000;
constexpr unsigned int no_edge=0xFFFFFFFF;

/*matrix presentation*/
int G[max_v_n][max_v_n];
bool vis[max_v_n]={false};
/*adj table presentation*/
vector<int> adj_t[max_v_n];
bool vis_t[max_v_n]={false};

void dfs_matrix_vertex(int u,int n,int depth)
{
        vis[u]= true;
        cout<<u;
        for(int v_i=0;v_i<n;v_i++){
                if(!vis[v_i]&&G[u][v_i]!=no_edge){
                        dfs_matrix_vertex(v_i,n,depth+1);
                }
        }
}
void dfs_graph_matrix(int n)
{
        for(int v_i=0;v_i<n;v_i++){
                if(!vis[v_i]){
                        dfs_matrix_vertex(v_i,n,1);
                }
        }
}
void dfs_adj(int u,int n,int depth)
{
        vis_t[u]=true;
        cout<<u;
        for(int v : adj_t[u]){
                if(!vis_t[v]){
                        dfs_adj(v,n,depth+1);
                }
        }
}
void dfs_graph_adj(int n)
{
        for(int v_i=0;v_i<n;v_i++){
                if(!vis_t[v_i]){
                        dfs_adj(v_i,n,1);
                }
        }
}

