/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/2/14
 */

#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <algorithm>

#define All(x)  x.begin(),x.end()
#define Ins(x) inserter(x,x.begin())
using namespace std;
int G[11][11];
int C[100];
int cnt_combs;
/* if 3 dots are from these sets
 * they are forbidden*/
vector<set<int>> forbid{
        {0, 2, 6},
        {0, 3, 7, 9},
        {0, 4, 8},
        {1, 2, 3, 8},
        {1, 3, 4, 5},
        {6, 7, 8}
};
/*whether 3 dots are in one line*/
bool judge_set(set<int> s)
{
        set<int> x;
        for (auto Set:forbid) {
                set_intersection(All(s), All(Set), Ins(x));
                if (x.size() == 3) {
                        return false;
                }
                x.clear();
        }
        return true;
}
/*consist a triangle?*/
bool is_triangle(set<int> s)
{
        int vi[3] = {0};
        int i = 0;
        for (int it : s) {
                vi[i++] = it;
        }
        int a = vi[0];
        int b = vi[1];
        int c = vi[2];

        return G[a][b] && G[b][c] && G[a][c];
}

/*all Cnr*/
void get_comb(int N, int r, vector<set<int>>&Combs)
{
        int i, j;
        for (i = N; i >= r; i--) {
                C[r] = i;
                if (r > 1)
                        get_comb(i - 1, r - 1, Combs);
                else {
                        cnt_combs++;
                        set<int> S;
                        for (j=C[0];j>0;j--)
                                S.insert(C[j]-1);
                        /*if this set are not in a line */
                        if(judge_set(S)&&is_triangle(S)){
                                Combs.push_back(S);
                        }
                }
        }
}

int main()
{
        int N;
        int e;
        scanf("%d %d", &N, &e);
        for (int i = 0; i < e; i++) {
                int u, v;
                scanf("%d %d", &u, &v);
                G[u][v] = 1;
                G[v][u] = 1;
        }
        /* method 1  map&set to get combinations */
        vector<set<int>> Ans1;
        map<set<int>, int> M;
        set<int> S;
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                        for (int k = 0; k < N; k++) {
                                S.insert(i);
                                S.insert(j);
                                S.insert(k);
                                if (S.size() == 3) {
                                        M[S]++;
                                        if (M[S] == 1 && judge_set(S)&&is_triangle(S)) {
                                                Ans1.push_back(S);
                                        }
                                }
                                S.clear();
                        }
                }
        }
        printf("ans=%d\n", Ans1.size());
        /* method 2 recursion to get combinations */
        C[0]=3;
        vector<set<int>>Ans2;
        get_comb(N,3,Ans2);
        printf("ans=%d\n",Ans2.size());



        return 0;
}