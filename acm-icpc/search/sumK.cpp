/*给定一个序列：a1,a2,...,an 给出一个数K，判断是否可以从序列中选出部分数
 * 使得其和为K，若存在输出yes，若不存在输出no*/
#include <cstdio>

#define max_n 21
using namespace std;
int n;
int arr[max_n];
int k;

/*搜索了前i项了，和为sum*/
bool dfs(int i, int sum)
{
        if (i == n) { return sum == k; }
        if (dfs(i + 1, sum)) { return true; }
        if (dfs(i + 1, sum + arr[i])) { return true; }
        return false;
}

int main()
{
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
        }
        scanf("%d", &k);
        if (dfs(0, 0)) {
                printf("yes\n");
        } else {
                printf("no\n");
        }
        return 0;
}