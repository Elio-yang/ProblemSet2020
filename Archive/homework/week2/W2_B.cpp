#include <cstdio>
#include <cstdlib>
#include <cstring>
#define inf 16843009
using namespace std;

int A[30000+10];
int my_cmp(const void * a,const void * b)
{
        return *((int*)a)>*((int*)b);
}

int main()
{
        memset(A,1,sizeof(A));
        int n,m;
        scanf("%d %d",&n,&m);
        int index[1000+10];
        for (int i = 0; i < n; i++) {
                int id;
                scanf("%d",&id);
                A[id]=id;
                index[i]=id;
        }
        for (int i = 0; i < m; i++) {
                int id;
                scanf("%d",&id);
                A[id]=inf;
        }
        int cnt=0;
        int sub_set[n];
        for(int i=0;i<n;i++){
                if(A[index[i]]!=inf){
                        sub_set[cnt++]=A[index[i]];
                }
        }
        qsort(sub_set,cnt,sizeof(int),my_cmp);
        if(cnt==0){
                printf("0\n");
        }else{
                for (int i = 0; i < cnt; i++) {
                        printf("%d ",sub_set[i]);
                }
                printf("\n");
        }
}