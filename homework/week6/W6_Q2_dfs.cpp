#include <cstdio>
#include <iostream>
#include <climits>

using namespace std;
const int maxn=205;


struct point{
        int x;
        int y;
};

struct Palace{
        int n,m;
        int G[maxn][maxn];
        point start;
        bool vis[maxn][maxn]={false};
        int dis[4][2]={
                {0,1},
                {1,0},
                {0,-1},
                {-1,0}

        };
        point end;
        int min=INT_MAX;
        int ans;
        Palace(int l,int w):n(l),m(w){
        }
        void dfs(int x,int y,int steps){
                if(x==end.x&&y==end.y){
                        if(steps<min){
                                min=steps;
                        }
                        return;
                }
                int n_x;
                int n_y;
                for (int i = 0; i < 4; i++) {
                        n_x=x+dis[i][0];
                        n_y=y+dis[i][1];
                        if(n_x<0||n_x>=m||n_y<0||n_y>=n){
                                continue;
                        }
                        if(G[n_x][n_y]==0&&!vis[n_x][n_y]){
                                vis[n_x][n_y]= true;
                                dfs(n_x,n_y,steps+1);
                                vis[n_x][n_y]= false;
                        }
                }
                return;
        }
};

int main()
{
        int n,m;//long width
        scanf("%d %d",&n,&m);
        Palace P(n,m);
        for (int i=0;i<n;i++){
                for (int j = 0; j < m; j++) {
                        int s;
                        scanf("%d",&s);
                        P.G[i][j]=s;
                        if (s==3){
                                P.start.x=i;
                                P.start.y=j;
                                P.vis[i][j]= true;
                                P.G[i][j]=0;
                        }
                        if (s==4){
                                P.end.x=i;
                                P.end.y=j;
                                P.G[i][j]=0;
                        }
                }
        }

        P.dfs(P.start.x,P.start.y,0);
        if(P.min!=INT_MAX){
                printf("%d",P.min);
        }else{
                printf("unreachable\n");
        }

        return 0;
}

/*
5 5
1 0 1 1 1
1 0 0 1 0
1 0 0 1 0
0 0 0 1 0
1 0 0 0 1
5 3 2 3
 */
