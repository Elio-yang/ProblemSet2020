#include <bits/stdc++.h>
using namespace std;

int ans;
int sx,sy;
int ex,ey;
int m,n,t;
int Maze[8][8];

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
bool vis[8][8]={false};

void dfs(int x,int y)
{
        if (x==ex&&y==ey){
                ans++;
                return;
        }else{
                for (int i = 0; i < 4; i++) {
                        int nx=x+dx[i];
                        int ny=y+dy[i];
                        /* 四个方向dfs */
                        if (1<=nx&&nx<=n&&1<=ny&&ny<=m&&!vis[nx][ny]&&Maze[nx][ny]==0){
                                vis[nx][ny]= true;
                                dfs(nx,ny);
                                vis[nx][ny]= false;
                                /* 标记为已经访问--->搜索--->取消标记（回溯）*/
                        }
                }
        }
}
int main()
{
        scanf("%d %d %d",&n,&m,&t);
        memset(Maze,0,sizeof(Maze));
        scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
        for (int i = 0; i < t; i++) {
                int x,y;
                scanf("%d %d",&x,&y);
                Maze[x][y]=1;
        }
        /* !!起点要标记为已经访问过 */
        vis[sx][sy]=true;
        dfs(sx,sy);
        printf("%d",ans);
        return 0;
}