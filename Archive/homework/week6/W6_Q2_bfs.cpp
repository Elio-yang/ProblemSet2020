#include<iostream>
#define inf 99999999
using namespace std;
typedef struct point{
        int X;
        int Y;
        point(int x,int y): X(x), Y(y){}
}p;
int vis[105][105],n,m,sx,sy;
int G[105][105];

struct Queue{
        int size;
        int Front;
        int Rear;
        p* queue;
        explicit Queue(int n): size(0), Front(1), Rear(0){
                queue=(p*)malloc(sizeof(point)*n);
        }
        int empty() const{return size==0;}
        p front() const{return queue[Front];}
        void push(p ele){size++;Rear++;queue[Rear]=ele;}
        void pop(){size--;Front++;}

};

int bfs(int x,int y){
        Queue Q(1000);
        Q.push(p(x, y));
        while(Q.size){
                p p1= Q.front();
                Q.pop();
                if(G[p1.X][p1.Y] == 4){
                        return vis[p1.X][p1.Y];
                }
                for(int i=-1;i<=1;i++){
                        for(int j=-1;j<=1;j++){
                                if(i==0&&j==0||i==1&&j==1||i==-1&&j==1||i==1&&j==-1||i==-1&&j==-1)
                                        continue;
                                int i1= p1.X + i,j1= p1.Y + j;
                                if(i1>=0 &&i1<n &&j1>=0 &&j1<m && (G[i1][j1] == 0 || G[i1][j1] == 4) && vis[i1][j1] == inf){
                                        vis[i1][j1]= vis[p1.X][p1.Y] + 1;
                                        Q.push(p(i1, j1));
                                }
                        }
                }
        }
        return inf;
}
int main()
{
        cin>>n>>m;
        for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                        vis[i][j]=inf;
                        cin >> G[i][j];
                        if(G[i][j] == 3){
                                sx=i;sy=j;
                                vis[i][j]=0;
                        }
                }
        }
        int ans=bfs(sx, sy);
        if(ans != inf){
                cout << ans << endl;
        }else{
                cout<<"unreachable"<<endl;
        }
        system("pause");
        return 0;
}