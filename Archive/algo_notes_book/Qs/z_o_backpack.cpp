#include <cstdio>

const int max_n=30;
int n,V,max_v=0;
int w[max_n];
int c[max_n];
static int ans_w[max_n];
void dfs(int id,int sum_w,int sum_c)
{
        if(id>=n){/*死胡同*/
                if(sum_w<=V&&sum_c>=max_v){
                        max_v=sum_c;
                }
        }else{/*岔路口*/
                dfs(id+1,sum_w,sum_c);
                dfs(id+1,sum_w+w[id],sum_c+c[id]);
        }
}
int main()
{
        scanf("%d%d",&n,&V);
        for (int i=0;i<n;i++){
                scanf("%d",&w[i]);
        }
        for (int i = 0; i < n;++i) {
                scanf("%d",&c[i]);
        }
        dfs(0,0,0);
        printf("%d\n",max_v);
        return 0;
}


