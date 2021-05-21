#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
constexpr int max_vertex = 5;
constexpr int inf = INT_MAX;
constexpr int n = max_vertex;
/*G[i][j]==inf 说明不存在这条边*/
int G[max_vertex][max_vertex] = {
        {inf, 2,   inf, inf, 1},
        {2,   inf, 2,   inf, 2},
        {inf, 2,   inf, 1,   inf},
        {inf, inf, 1,   inf, 1},
        {1,   2,   inf, 1,   inf}
};
bool vis_m[n] = {false};

void bfs(int v);
void dfs(int v, int depth);

void graph_traversal();

int main()
{
        graph_traversal();
        return 0;
}


void bfs(int v)
{
        queue<int> Q;
        vis_m[v] = true;
        Q.push(v);
        cout<<"find vertex: "<<v<<endl;
        while (!Q.empty()) {
                int v=Q.front();
                Q.pop();
                for(int i=0;i<n;i++){
                        if(!vis_m[i]&&G[v][i]!=inf){
                                Q.push(i);
                                vis_m[i]= true;
                                cout<<"find vertex: "<<i<<endl;
                        }
                }
        }
}
void dfs(int v, int depth)
{
        vis_m[v]= true;
        cout<<"depth"<<depth<<" find vertex: "<<v<<endl;
        for(int i=0;i<n;i++){
                int v_i=G[v][i];
                if(!vis_m[i]&&v_i!=inf){
                        dfs(i,depth+1);
                }
        }
}
void graph_traversal()
{
        cout << "dfs_a: ";
        for (int j = 0; j < n; j++) {
                if (!vis_m[j]) {
                        dfs(j, 1);
                }
        }
        cout << "----------dfs_a done!------------" << endl;

        cout << "bfs_a: ";
        fill(vis_m, vis_m + n, false);
        bfs(0);
        cout << "----------bfs_a done!--------------" << endl;
}



