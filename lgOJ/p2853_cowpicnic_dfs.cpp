#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
const int maxn = 1100;
const int cown = 110;
const int inf = 0x3f3f3f3f;

int count[maxn];

bool vis[maxn];

int cow_id[cown];

int ans;

int G[maxn][maxn];

class pasture {
public:
        int n;
        int e;
        int k;

        pasture(int K, int N, int E) : k(K), n(N), e(E)
        {}

        void dfs(int s);

        void tra();
};

void pasture::dfs(int s)
{
        vis[s] = true;
        count[s]++;
        if (count[s] == k) {
                ++ans;
        }
        for (int i = 1; i <= n; i++) {
                if (G[s][i] != inf && !vis[i]) {
                        dfs(i);
                }
        }
}

void pasture::tra()
{
        for (int i = 1; i <= k; i++) {
                memset(vis, 0, sizeof(vis));
                dfs(cow_id[i]);
        }
}

int main()
{
        int k, n, m;
        scanf("%d %d %d", &k, &n, &m);
        pasture P(k, n, m);
        for (int i = 1; i <= k; i++) {
                /*牛在哪些牧场*/
                scanf("%d", &cow_id[i]);
        }
        memset(G, 0x3f, sizeof(G));
        for (int i = 0; i < m; i++) {
                int u, v;
                scanf("%d %d", &u, &v);
                G[u][v] = 1;
        }
        P.tra();
        printf("%d\n", ans);
        return 0;
}

