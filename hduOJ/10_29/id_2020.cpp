#include <cstdio>
#include <algorithm>

int mycmp(int a,int b)
{
        return abs(a)>abs(b);
}
int main()
{
        int n;
        while((scanf("%d",&n))!=EOF){
                if(n==0){
                        continue;
                }
                int val[n];
                for(int i=0;i<n;i++){
                        scanf("%d",&val[i]);
                }
                std::sort(val,val+n,mycmp);
                for(int i=0;i<=n-2;i++){
                        printf("%d ",val[i]);
                }
                printf("%d\n",val[n-1]);
        }
        return 0;
}