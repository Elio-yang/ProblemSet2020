#include <iostream>

struct edge {
        int v;
        int w;
        edge *next;
};

struct recd {
        int sum;
        /*longest path*/
        int l_st;
        int pos;
};

const int maxn = 10010;
const int inf = 0x3f3f3f3f;
recd key_path;
int vis[maxn] = {0};
edge Adj[maxn];

void dfs(recd recd_data, int s, int t)
{
        edge *p = Adj[s].next;
        if (s == t) {
                if (((recd_data.sum - recd_data.l_st) < (key_path.sum - key_path.l_st)) ||
                    (((recd_data.sum - recd_data.l_st) == (key_path.sum - key_path.l_st)) &&
                     (recd_data.pos < key_path.pos))) {
                        key_path = {recd_data.sum, recd_data.l_st, recd_data.pos};
                }
        } else {
                while (p != nullptr) {
                        if (vis[p->v] == 0) {
                                /*当前的记录*/
                                recd cur;
                                cur = {recd_data.sum, recd_data.l_st, recd_data.pos};
                                /*访问节点*/
                                vis[p->v] = 1;
                                if (p->w > cur.l_st) {
                                        cur.l_st = p->w;
                                        cur.pos = s;
                                } else if (p->w == cur.l_st && s < cur.pos) {
                                        //更新编号小的
                                        cur.l_st = p->w;
                                        cur.pos = s;

                                }
                                cur.sum = cur.sum + p->w;
                                dfs(cur, p->v, t);
                                vis[p->v] = 0;
                                /*取消访问记录*/
                        }
                        p = p->next;
                }
        }
}

int main()
{
        key_path = {inf, 0, 0};
        int n, s, t, e;
        scanf("%d %d %d %d", &n, &s, &t, &e);

        for (int i = 0; i < maxn; i++) {
                Adj[i].next = nullptr;
        }
        for (int i = 0; i < e; i++) {
                int u, v, w;
                scanf("%d %d %d", &u, &v, &w);

                edge *E_1 = new edge;
                E_1->next = nullptr;
                E_1->v = v;
                E_1->w = w;
                E_1->next = Adj[u].next;
                Adj[u].next = E_1;


                edge *E_2 = new edge;
                E_2->next = nullptr;
                E_2->v = u;
                E_2->w = w;
                E_2->next = Adj[v].next;
                Adj[v].next = E_2;
        }
        /*建立邻接表*/

        recd more;
        more = {0, 0, 0};
        vis[s] = 1;
        dfs(more, s, t);
        printf("%d %d", key_path.sum - key_path.l_st, key_path.pos);
        return 0;
}
