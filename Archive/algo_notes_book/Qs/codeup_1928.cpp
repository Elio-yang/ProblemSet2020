#include<bits/stdc++.h>
#include<time.h>
using namespace std;
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
        int date1,y1,m1,d1;
        int date2,y2,m2,d2;
        while(cin>>date1>>date2){
                if(date1>date2){
                        int tmp=date1;
                        date1=date2;
                        date2=tmp;
                }
                /*假设第一个日期短，否则就交换*/
                /*data1 20130101*/
                y1=date1/10000;/*-->2013*/
                m1=date1%10000/100;/*-->101/100=1*/
                d1=date1%100;/*-->1*/

                y2=date2/10000;
                m2=date2%10000/100;
                d2=date2%100;

                int ans=1;
                /*连续的两天，差值为2*/
                while(y1<y2||m1<m2||d1<d2){
                        d1++;
                        
                         #define __isleap(year) \
                         ((year) % 4 == 0 && ((year) % 100 != 0 || (year) % 400 == 0))
                         
                        if(d1==month[m1][__isleap(y1)]+1){
                        /*是否满月？*/
                                m1++;
                                d1=1;
                        }
                        if(m1==13){
                        /*是否满一年*/
                                y1++;
                                m1=1;
                        }
                        ans++;
                        /*增加一天*/
                }
                cout<<ans<<endl;
        }
        return 0;
}