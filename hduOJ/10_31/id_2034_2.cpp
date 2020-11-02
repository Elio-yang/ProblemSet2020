#include <cstdio>
#include <cstdlib>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
        int m,n;
        while(~scanf("%d %d",&m,&n)){
                if(m==0&&n==0){
                        continue;
                }
                int A[110]={0};
                for(int i=0;i<m;i++){
                        int ele;
                        scanf("%d",&ele);
                        A[ele]=ele;
                }
                for(int i=0;i<n;i++){
                        int ele;
                        scanf("%d",&ele);
                        A[ele]=0;
                }
                bool f=false;
                for(int i=0;i<110;i++){
                        if(A[i]!=0){
                                printf("%d ",A[i]);
                                f=true;
                        }
                }
                if(!f){
                        printf("NULL\n");
                        continue;
                }
                printf("\n");
        }
        system("pause");
        return 0;
}