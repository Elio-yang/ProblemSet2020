#include "queen_it.h"

int cnt_solu=0;
int cnt_check=0;

int main()
{
        int nq=4;
        place_queen(4,0);
        cout<<cnt_solu<<" solution(s) found after "
                    <<cnt_check<<" check(s) for "
                    <<nq<<" queen(s)\n";
        return 0;
}