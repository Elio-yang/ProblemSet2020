#include <cstdio>
#include <cstdlib>
/*回溯法*/
#define maxn 100000

void dfs(char *str, int len);

int main()
{
        int N;
        scanf("%d", &N);
        char *str = (char *) malloc(sizeof(char) * N);

        char ch = 'a';
        for (int i = 0; i < N; i++) {
                str[i] = ch++;
        }
        dfs(str, N);
        return 0;
}

void dfs(char *str, int len)
{
        int i, cnt = 0;
        char ans[maxn];
        ans[cnt] = 'a';
        printf("{}\n");
        do {
                printf("{");
                for (i = 0; i < cnt; i++) {
                        printf("%c,", ans[i]);
                }
                printf("%c", ans[i]);/*处理逗号*/
                printf("}\n");

                if (ans[cnt] < 'a' + len - 1) {
                        ans[cnt + 1] = ans[cnt] + 1;
                        ++cnt;
                } else if (cnt) {
                        ans[--cnt] += 1;
                } else {
                        break;
                }
        } while (1);
}
