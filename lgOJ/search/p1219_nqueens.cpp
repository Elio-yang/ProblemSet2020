/*
 N 皇后问题： 回溯法
 要开O2优化
 */
#include <cstdio>
#include <vector>

using namespace std;
const int maxn=15;
const int max_solu=74000;
vector<vector<int>> ans;
int solus;
//判断是否冲突
bool is_collision(int*pos,int k)
{
        for (int i = 1; i < k; i++) {
                if (pos[i] == pos[k]) return true;
                if (pos[k] + k == pos[i] + i) return true;
                if (pos[k] - k == pos[i] - i) return true;
        }
        return false;
}

//摆放第k个皇后，前k-1个都已经摆放完毕
void place_queue(int q_num,int k)
{
        static int Colums[maxn];
        if (k>=q_num+1){
                solus++;
                vector<int> tmp;
                for (int i = 1; i <= q_num; i++) {
                        tmp.push_back(Colums[i]);
                }
                ans.push_back(tmp);
        }else{
                for (int i = 1; i <=q_num ; i++) {
                        Colums[k]=i;
                        if (!is_collision(Colums,k)){
                                place_queue(q_num,k+1);
                        }

                }

        }
}

int main()
{
        int n;
        scanf("%d",&n);
        place_queue(n,1);
        for (int i = 0; i < 3; i++) {
                for (auto item:ans[i]){
                        printf("%d ", item);
                }
                printf("\n");
        }
        printf("%d",solus);
        return 0;
}


