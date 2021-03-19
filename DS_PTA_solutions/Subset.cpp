/*
 给定两个非空集合A和B，集合的元素为30000以内的正整数，编写程序求A-B。

输入格式:
输入为三行。     第1行为两个整数n和m，分别为集合A和B包含的元素个数，1≤n, m ≤10000。
                第2行表示集合A，为n个空格间隔的正整数，每个正整数不超过30000。
                第3行表示集合B，为m个空格间隔的正整数，每个正整数不超过30000。

输出格式:
输出为一行整数，表示A-B，每个整数后一个空格，各元素按递增顺序输出。
若A-B为空集，则输出0，0后无空格。

输入样例:

5 5
1 2 3 4 5
3 4 5 6 7


输出样例:

1 2

 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#define inf 16843009
using namespace std;

int A[30000+10];
int my_cmp(const void * a,const void * b)
{
        return *((int*)a)-*((int*)b);
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