#pragma once

#include <iostream>
using namespace std;
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

int n_solu=0;//解的总数
int n_check=0;//尝试的总次数

class Queen{
public:
        int x;
        int y;
        explicit Queen(int xx=0,int yy=0):x(xx),y(yy){};
        /*重载==运算符，判断是否会冲突*/
        bool operator==(Queen const &q)const{
                return (q.x==x)||       //行冲突
                       (q.y==y)||      //列冲突
                       (x+y==q.x+q.y)||//正对角线
                       (x-y==q.x-q.y); //反对角线
                /*
                 * ----------------
                 * |  |1 |2 |3 |  |
                 * ----------------
                 * |  |4 |* |  |  |
                 * ----------------
                 * |  |5 |  |6 |  |
                 * ----------------
                 *   queen * (x,y)
                 *   1: (x-1,y+1)--->x-1+y+1==x+y
                 *   2:  2.y==y
                 *   3: (x+1,y+1)--->x+1-y-1=x-y
                 *   4: 4.x==x
                 *   5: (x-1,y-1)--->x-1-y+1==x-y
                 *   6: (x+1,y-1)--->x+1+y-1==x+y
                 * */
        }
        bool operator!=(Queen const &q)const{
                return !(*this==q);
        }
};
void place_queen(int);
void display_row(Queen &q,int);

int main()
{
        int nQ=8;
        place_queen(nQ);
        cout<<n_solu<<" solution(s) found after "<<n_check<<" check(s) for "<<nQ<<" queen(s)\n";
        return 0;
}


void place_queen(int N)
{
        vector<Queen> ans;
        Queen q(0,0);
        do {
                if((ans.size()>=N)||(q.y>=N)){//已经出界限
                        q=ans[ans.size()-1];//回溯一行,继续试探下一列
                        ans.pop_back();
                        q.y++;
                }else{//试探下一列
                        while ((q.y<N)&&(find(ans.begin(),ans.end(),q)!=ans.end())){
                                q.y++;
                                n_check++;
                        }
                        if(q.y<N){
                                ans.push_back(q);
                                if(ans.size()>=N){
                                        /*得到一组可行解*/
                                        n_solu++;
                                        for(auto & it : ans){
                                                display_row(it,N);
                                        }
                                        cout<<endl;
                                }
                                q.x++;
                                q.y=0;//下一行，从第0列开始
                        }
                }
        }while ((q.x>0)||(q.y<N));
}

void display_row(Queen &q,int N)
{
        printf("%2d: ",q.x);
        int i=0;
        while (i++<q.y)printf("[]");
        printf("*");
        while (i++<N)printf("[]");
        printf("%2d\n",q.y);
}
