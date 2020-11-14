#include "queen_stk.h"
int n_solu=0;//解的总数
int n_check=0;//尝试的总次数

int main()
{
        int nQ=4;
        place_queen(nQ);
        cout<<n_solu<<" solution(s) found after "<<n_check<<" check(s) for"<<nQ<<" queen(s)\n";
        return 0;
}