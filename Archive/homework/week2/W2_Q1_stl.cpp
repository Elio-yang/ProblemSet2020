#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <stack>

using namespace std;
#define maxn 1000000

char ops_arr[maxn];
int val_arr[maxn];

stack<int> val_stk;
stack<char> ops_stk;

bool Errno = false;

int op_order(char c1, char c2)
{
        if (c1 == '(' || c2 == '(')return 0;
        /*说明c2!='(,c2必然优先级大于等于c1*/
        if (c1 == '+' || c1 == '-')return 1;
        if (c1 == '*' && (c2 == '*' || c2 == '/'))return 1;
        if (c1 == '/' && (c2 == '*' || c2 == '/'))return 1;
        /*c1的优先级大于c2*/
        return 0;
}


int calc(char ops, int op1, int op2);

int main()
{
        char post_str[maxn];
        scanf("%s", post_str);
        memset(ops_arr, 0, sizeof(ops_arr));

        int len = strlen(post_str);
        post_str[len] = ')';
        int cur = 0;
        ops_stk.push('(');

        for (int i = 0; i <= len;) {
                if (isdigit(post_str[i])) {
                        int val = 0;
                        while (i < len && isdigit(post_str[i])) {
                                val = 10 * val + (post_str[i] - '0');
                                i++;
                        }
                        val_arr[cur++] = val;
                } else {
                        if (post_str[i] == ')') {
                                while (!ops_stk.empty() && ops_stk.top() != '(') {
                                        ops_arr[cur++] = ops_stk.top();
                                        ops_stk.pop();
                                }
                                ops_stk.pop();
                        } else {
                                while (!ops_stk.empty() && (op_order(post_str[i], ops_stk.top()))) {
                                        /*
                                          栈顶运算符的优先级比读到的运算符的优先级高
                                          或二者相等，弹出栈顶运算符放入后缀表达式中
                                        */
                                        ops_arr[cur++] = ops_stk.top();
                                        ops_stk.pop();
                                }
                                ops_stk.push(post_str[i]);
                        }
                        i++;
                }
        }
        for (int i = 0; i < cur; i++) {
                if (!ops_arr[i]) {
                        val_stk.push(val_arr[i]);
                } else {
                        int v2 = val_stk.top();
                        val_stk.pop();
                        int v1 = val_stk.top();
                        val_stk.pop();
                        int val = calc(ops_arr[i], v1, v2);
                        val_stk.push(val);
                }
        }
        if (!Errno) {
                printf("%d\n", val_stk.top());
        } else {
                printf("ILLEGAL\n");
        }
        system("pause");
        return 0;
}


int calc(char ops, int op1, int op2)
{
        int ans;
        switch (ops) {
                case '+': {
                        ans = op1 + op2;
                        break;
                }
                case '-': {
                        ans = op1 - op2;
                        break;
                }
                case '*': {
                        ans = op1 * op2;
                        break;
                }
                case '/': {
                        if (op2 == 0) {
                                Errno = true;
                                return -1;
                        } else {
                                double res = op1 / op2;
                                if (res < 0) {
                                        ans = ceil(res);
                                } else {
                                        ans = floor(res);
                                }
                                /*向上取整 ceil
                                  向下取整 floor
                                  四舍五入 round
                                */
                        }
                        break;
                }
        }
        return ans;
}