#include <iostream>
#include <cstring>

const int maxn = 300;
#define BOMB -4

struct FIND_BOMB {
        int m, n;
        int bomb_num;
        int map[maxn][maxn];

        FIND_BOMB(int M, int N, int bombNum = 0) :
                m(M), n(N), bomb_num(bombNum)
        {
                memset(map, -1, sizeof(map));
                for (int i = 0; i < bomb_num; i++) {
                        int x, y;
                        scanf("%d %d", &x, &y);
                        map[x][y] = BOMB;
                }
        }

        inline bool in_range(int x, int y) const
        {
                return (0 <= x && x < m && 0 <= y && y < n);
        }

        int count_bomb(int x, int y)
        {
                int cnt = 0;
                for (int i = -1; i <= 1; i++) {
                        for (int j = -1; j <= 1; j++) {
                                int nx = x + i;
                                int ny = y + j;
                                if (i == 0 && j == 0) {}
                                else if (in_range(nx, ny) && map[nx][ny] == BOMB) {
                                        cnt++;
                                }
                        }
                }
                return cnt;
        }

        void expand_area(int x, int y)
        {
                int cnt = count_bomb(x, y);
                if (cnt == 0 && map[x][y] == -1) {
                        map[x][y] = 0;
                        for (int i = -1; i <= 1; i++) {
                                for (int j = -1; j <= 1; j++) {
                                        /*
                                         -1 -1  左下
                                         -1 0   左
                                         -1 1   左上
                                         0 -1   下
                                         0 1    上
                                         1 -1   右下
                                         1 0    右
                                         1 1    右上
                                         */
                                        int nx = x + i;
                                        int ny = y + j;
                                        if (i == 0 && j == 0) {}
                                        else if (in_range(nx, ny)) {
                                                expand_area(nx, ny);
                                        }
                                }
                        }
                } else {
                        map[x][y] = cnt;
                }
        }

        void show()
        {
                for (int i = 0; i < m; i++) {
                        for (int j = 0; j < n; j++) {
                                if (map[i][j] == BOMB) {
                                        printf("-1 ");
                                } else {
                                        printf("%d ", map[i][j]);
                                }
                        }
                        printf("\n");
                }
                if (is_win()) { printf("You win\n"); }
                else { printf("\n"); }
        }

        bool is_bomb(int x, int y)
        {
                return map[x][y] == BOMB;
        }

        bool is_win()
        {
                int cnt = 0;
                for (int i = 0; i < m; i++) {
                        for (int j = 0; j < n; j++) {
                                if (map[i][j] == -1) {
                                        cnt++;
                                }
                        }
                }
                return cnt == 0;
        }
};

int main()
{
        int m, n, k, l;
        scanf("%d %d %d %d", &m, &n, &k, &l);
        FIND_BOMB game(m, n, k);
        for (int i = 0; i < l; i++) {
                int x, y;
                scanf("%d %d", &x, &y);
                if (game.is_bomb(x, y)) {
                        printf("You lose\n");
                        break;
                } else {
                        if (!game.in_range(x, y) || game.map[x][y] == 0) { continue; }
                        game.expand_area(x, y);
                        game.show();
                        if (game.is_win()) { continue; }
                }
        }
        return 0;

}
