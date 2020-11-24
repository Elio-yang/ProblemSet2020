#include <cstdio>
#include <cstring>
#include <algorithm>
#define size 110
#define inf 16843009
using namespace std;
int G[size][size];
int D[size][size];
bool vis[size]={false};
void floyd(int n)
{
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        D[i][j]=G[i][j];
                }
        }
        for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                                if(D[i][j]>(D[i][k]+D[k][j])){
                                        D[i][j]=D[i][k]+D[k][j];
                                }
                        }
                }
        }
}

void dfs(int s,int n,int d,bool *f)
{
        vis[s]= true;
        if(s==d){
                *f= true;
        }
        for (int i = 0; i < n; i++) {
                if(G[s][i]!=inf){
                        dfs(i,n,d,f);
                }
        }
}

int main()
{
        int n,e,m;
        while ((scanf("%d %d %d",&n,&e,&m))!=EOF){
                fill(vis,vis+size, false);
                memset(G,1,sizeof(G));
                for(int i=0;i<e;i++){
                        int i1,i2,w;
                        scanf("%d %d %d",&i1,&i2,&w);
                        G[i1][i2]=w;
                }
                bool f= false;
                floyd(n);
                for(int i=0;i<n;i++){
                        if(D[i][i]<0){f= true;break;}
                }
                for(int i=0;i<m;i++){
                        int x,y;
                        scanf("%d %d",&x,&y);
                        bool f1= false;
                        bool f2= false;
                        dfs(x,n,y,&f1);
                        dfs(y,n,x,&f2);
                        if(!f)
                        {
                                if(f1== false||f2== false){
                                        printf("none\n");
                                }else{
                                        printf("%d\n",D[x][y]);
                                }
                        }
                        fill(vis,vis+size, false);
                }
                if(f){
                        printf("negative circle\n");
                }
        }
        return 0;
}