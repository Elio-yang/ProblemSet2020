#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
        int m,n;
        int arr[100][100];
        int row,col;
        while((scanf("%d %d",&n,&m))!=EOF){
                int score=0;
                for(int i=1;i<=n;i++){
                        for(int j=1;j<=m;j++){
                                scanf("%d",&arr[i][j]);
                                if(abs(arr[i][j])>abs(score)){
                                        score=arr[i][j];
                                        row=i;
                                        col=j;
                                }
                        }
                }
                printf("%d %d %d\n",row,col,score);
        }
        return 0;
}