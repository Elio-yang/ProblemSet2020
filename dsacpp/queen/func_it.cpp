#include "queen_it.h"



/*放置第k个皇后，假设0~k-1都已经放置好了*/
void place_queen(int n_q,int k)
{
        static int solu[max_q];
        /*递归终止，得到了一组可行解*/
        if(k>=n_q){
                cnt_solu++;
                display_queen(solu,n_q);
                cout<<endl;
        }
        else{
                for(int i=0;i<n_q;i++){
                        /* 第k个皇后(即第k行的皇后)分别放置在0~n-1列
                         * 在判断是否冲突*/
                        solu[k]=i;
                        if(!collision(solu,k)){
                                /*不冲突就考虑下一个皇后*/
                                place_queen(n_q,k+1);
                        }
                }
        }
        /*执行到此处，说明该皇后无位置可放，回溯至上一皇后*/

}
void display_queen(int *solu,int n)
{
        for(int i=0;i<n;i++){
                printf("%-2d",i);
                for(int j=0;j<n;j++){
                        printf((j==solu[i])?"*":"[]");
                }
                printf("%2d",solu[i]);
                cout<<endl;
        }
}
bool collision(int*solu,int k)
{
        cnt_check++;
        for(int i=0;i<k;i++){
                /*
                 * 皇后的坐标是(k,solu[k])
                 * 当前皇后在第k行，列为solu[k]
                 * 判断前面各行的皇后与此皇后是否有冲突即可
                 * */
                if(solu[k]==solu[i]) return true;
                if(solu[k]-k==solu[i]-i) return true;
                if(i+solu[i]==k+solu[k]) return true;
        }
        return false;
}
