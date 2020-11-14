#include "queen_stk.h"

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

