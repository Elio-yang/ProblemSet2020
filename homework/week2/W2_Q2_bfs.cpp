#include <stdio.h>
#include <stdlib.h>
/*回溯法*/
#define maxn 100000
void bfs(char *str, int n, int len);
int main()
{
    int N;
    char ch='a';
    scanf("%d", &N);
    char* str = (char*)malloc(sizeof(char)*N);
    for (int i = 0; i < N; i++){
        str[i] = ch++;
    }    
    int k = 0;
    bfs(str, k, N);
    system("pause");
    return 0;
}
void bfs(char *str, int n, int len)
{
    int i, cnt = 0;
    char ans[maxn];
    ans[cnt] = 'a';
    printf("{}\n");
    do{
        printf("{");
        for (i = 0; i < cnt; i++)
        {
            printf("%c,", ans[i]);
        }
        printf("%c",ans[i]);
        printf("}\n");

        if (ans[cnt] < 'a' + len - 1){
            ans[cnt + 1] = ans[cnt] + 1;
            ++cnt;
        }
        else if (cnt){
            ans[--cnt] += 1;
        }
        else{
            break;
        }
    }while(1);
}
