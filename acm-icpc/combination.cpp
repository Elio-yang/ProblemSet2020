#include <vector>

using namespace std;
int cnt_combs;
const int maxn = 100;
int C[maxn];

/*
 * All combinations of choosing r items from N
 * Combs to record all possible ways
 */
void get_combination(int N, int r, vector<vector<int>> &Combs)
{
        int i, j;
        for (i = N; i >= r; i--) {
                C[r] = i;
                if (r > 1)
                        get_combination(i - 1, r - 1, Combs);
                else {
                        cnt_combs++;
                        vector<int> ans;
                        for (j = C[0]; j > 0; j--)
                                ans.push_back(C[j]);
                        Combs.push_back(ans);
                }
        }
}


int Nums[maxn];
bool vis[maxn];

void dfs(int N, int r, int pos, int cnt, vector<vector<int>> Combs)
{
        if (cnt == r) {
                vector<int> ans;
                for (int i = 0; i < N; i++) {
                        if (vis[i]) {
                                ans.push_back(Nums[i]);
                        }
                }
        }
        if (pos == N) {
                return;
        }
        /* for the num at pos : choose or not? */
        if (!vis[pos]) {
                vis[pos] = true;
                /*
                 * the current num is chosen so cnt + 1
                 * choose k - 1 counts nums from Nums[pos+1] to Nums[N-1]
                 */
                dfs(N, r, pos + 1, cnt + 1, Combs);
                /*
                 * backtrace
                 */
                vis[pos] = false;
        } else {
                /*
                 * choose k counts nums from Nums[pos+1] to Nums[N-1]
                 */
                dfs(N, r, pos + 1, cnt, Combs);
        }
}


