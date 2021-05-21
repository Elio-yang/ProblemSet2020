#include <cstdio>

int main()
{
        int n;
        while((scanf("%d",&n))!=EOF){
                if(n==0){
                        continue;
                }
                int sal[n];
                int ans=0;
                for(int i=0;i<n;i++){
                        scanf("%d",&sal[i]);
                }
                for(int i=0;i<n;i++){
                        int all=sal[i];
                        int cnt_h=all/100;
                        int cnt_f=(all-100*cnt_h)/50;
                        int cnt_t=(all-100*cnt_h-50*cnt_f)/10;
                        int cnt_v=(all-100*cnt_h-50*cnt_f-10*cnt_t)/5;
                        int cnt_w=(all-100*cnt_h-50*cnt_f-10*cnt_t-5*cnt_v)/2;
                        int cnt_o=(all-100*cnt_h-50*cnt_f-10*cnt_t-5*cnt_v-2*cnt_w);
                        ans+=cnt_h+cnt_f+cnt_t+cnt_v+cnt_w+cnt_o;
                }
                printf("%d\n",ans);
        }
        return 0;
}