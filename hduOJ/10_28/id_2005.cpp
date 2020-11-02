#include <cstdio>
 #define __isleap(year) ((year) % 4 == 0 && ((year) % 100 != 0 || (year) % 400 == 0))
int month[13][2]={
        {0,0},
        /*月份从1月开始，数组的第0个要填充*/
        {31,31},
        {28,29},
        {31,31},
        {30,30},
        {31,31},
        {30,30},
        {31,31},
        {31,31},
        {30,30},
        {31,31},
        {30,30},
        {31,31}
};
int main()
{
        int y,m,d;
        while(scanf("%d/%d/%d",&y,&m,&d)!=EOF){
                int ans=1;
                int day_0=1;
                int m_0=1;
                while(m_0<m||day_0<d){
                        /*注意控制条件m_0<m,进入同一个月之后这个条件为假*/
                        day_0++;
                        if(day_0==month[m_0][__isleap(y)]+1){
                                m_0++;
                                day_0=1;
                        }
                        ans++;
                }
                printf("%d\n",ans);
        }
        return 0;
}