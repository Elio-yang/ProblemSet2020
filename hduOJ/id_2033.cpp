#include <cstdio>

int main()
{
        int n;
        scanf("%d",&n);
        int h_a,m_a,s_a;
        int h_b,m_b,s_b;
        while(n--){
                scanf("%d %d %d %d %d %d",&h_a,&m_a,&s_a,&h_b,&m_b,&s_b);
                int s_r=s_a+s_b;
                int c_s=s_r/60;
                int ans_s=s_r-60*c_s;

                int m_r=m_a+m_b+c_s;
                int c_m=m_r/60;
                int ans_m=m_r-60*c_m;

                int h_r=h_a+h_b+c_m;
                printf("%d %d %d\n",h_r,ans_m,ans_s);
        }
        
        return 0;
}