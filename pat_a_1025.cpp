#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Student{
    char id[15];
    int  score;
    int  room_num;
    int  rank;
}stu[30010];

bool my_cmp(Student a,Student b)
{
   if(a.score!=b.score){
       return a.score>b.score;
   }else{
       return strcmp(a.id,b.id)<0;
   }
}

int main()
{
    int n;
    int total;
    int cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>total;
        for(int j=0;j<total;j++){
            cin>>stu[cnt].id>>stu[cnt].score;
            stu[cnt].room_num=1;
            cnt++;
        }
        sort(stu+(cnt-total),stu+cnt,my_cmp);
        stu[cnt-total].rank=1;
        for(int i=cnt-total+1;i<cnt;i++){
            if(stu[i].score==stu[i-1].score){
                stu[i].rank=stu[i-1].rank;
            }else{
                stu[i].rank=i-(cnt-total)+1;
            }
        }
    }
    cout<<cnt<<endl;
    sort(stu,stu+cnt,my_cmp);
    int rank=1;
    for(int i=0;i<cnt;i++){
        if(i>0&&stu[i].score!=stu[i-1].score){
            rank=i+1;
        }
        cout<<stu[i].id<<" "<<stu[i].room_num<<" "<<stu[i].rank<<endl;
    }
    return 0;
}
