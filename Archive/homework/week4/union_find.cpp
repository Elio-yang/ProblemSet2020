#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
const int N = 1010; // 节点数量
int boss [N];

void init() {
        for (int i = 0; i < N; i++) {
                boss [i] = i;
        }
}

int g_l(int x) {
        if (boss [x] == x) {
                return x;
        }
        else {
                return g_l(boss [x]);
        }
}

void in_same_gang(int a, int b) {
        boss [g_l(a)] = g_l(b);
}

bool find(int a, int b) {
        return g_l(a) == g_l(b);
}

int main() {
        init();
        int gang_cnt = 0;
        int n, m, q;
        int person[N];

        memset(person, 0, sizeof(person));
        scanf("%d %d %d", &n, &m, &q);
        for (int i = 0; i < m; i++) {
                int id_a, id_b;
                scanf("%d %d", &id_a, &id_b);
                in_same_gang(id_a, id_b);
        }
        for (int i = 0; i < q; i++) {
                int p1, p2;
                scanf("%d %d", &p1, &p2);
                if (find(p1, p2)) {
                        printf("In the same gang.\n");
                }
                else {
                        printf("In different gangs.\n");
                }
        }



        int ans [N];
        memset(ans, 0, sizeof(ans));

        for (int i = 1; i <= n; i++) {
                int father = g_l(i);
                ans [father] = 1;
        }

        for (int i = 1; i <= n; i++) {
                gang_cnt += ans [i];
        }
        printf("%d\n", gang_cnt);
        return 0;
}