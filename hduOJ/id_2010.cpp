#include<cstdio>

int power(int val,int n)
{
        int ans=1;
        for(int i=1;i<=n;i++){
                ans*=val;
        }
        return ans;
}
int main()
{
        int m,n;
        while(scanf("%d %d",&m,&n)!=EOF){
                int val[10]={0};
                int cnt=0;
                for(int i=m;i<=n;i++){
                        int t=i/100;
                        int d=i%100/10;
                        int l=i%10;
                        int ans=power(t,3)+power(d,3)+power(l,3);
                        if(ans==i){
                                val[cnt++]=ans;
                        }
                        
                }
                if(cnt==0){
                        printf("no");
                }else{
                        for(int i=0;i>=0&&i<=cnt-2;i++){
                                printf("%d ",val[i]);
                        }
                        printf("%d",val[cnt-1]);
                }
                printf("\n");
        }
        return 0;
}