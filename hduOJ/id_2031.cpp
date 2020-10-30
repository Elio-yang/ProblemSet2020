#include <cstdio>

int main()
{
        int m,r;
        while((scanf("%d %d",&m,&r))!=EOF){
                unsigned int bits[32];
                bool flag=false;
                unsigned ans;
                if(m<0){
                        flag=true;
                        m=-m;
                }
                ans=m;
                int cnt=0;
                do{
                        bits[cnt++]=ans%r;
                        ans/=r;
                }while(ans!=0);
                if(flag){
                        printf("-");
                }
                for(int i=cnt-1;i>=0;i--){
                        if(bits[i]>=10){
                                printf("%c",'A'+bits[i]-10);
                        }else{
                                printf("%u",bits[i]);
                        }
                }
                printf("\n");       
        }
        return 0;
}