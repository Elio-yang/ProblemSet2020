#include<bits/stdc++.h>
using namespace std;
int main()
{
        int N;
        char c;
        cin>>N>>c;

        int row;
        if(N%2==0){
                row=N/2;
        }else{
                row=N/2+1;
        }
        char graph[row][N];
        memset(graph,' ',row*N);
        for(int i=0;i<row;i++){
                for(int j=0;j<N;j++){
                        if(i==0||i==row-1){
                                graph[i][j]=c;
                        }else{
                                graph[i][0]=c;
                                graph[i][N-1]=c;
                        }
                }
        }
        for(int i=0;i<row;i++){
                for(int j=0;j<N;j++){
                        cout<<graph[i][j];
                }
                cout<<endl;
        }
        return 0;
}