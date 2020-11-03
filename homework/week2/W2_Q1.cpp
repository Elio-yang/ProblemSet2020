#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <stack>

using namespace std;

#define N 1000010
#define top_S (-1)
#define maxn 1000000
char ops_arr[maxn];
int val_arr[maxn];

bool Errno=false;

struct stack_i{
    int Top;
    int * arr;
};
struct stack_c{
    int Top;
    char *arr;
};

void pop(struct stack_i * S);
void push(struct stack_i *S,int d);
int top(struct stack_i *S);
int empty(struct stack_i *S);
struct stack_i *creat_i();

void pop(struct stack_c * S);
void push(struct stack_c *S,int d);
int empty(struct stack_c *S);
struct stack_c *creat_c();
char top(struct stack_c *S);



int op_order(char c1,char c2);
int calc(char ops, int op1, int op2);

int main()
{
        char post_str[maxn];
        scanf("%s", post_str);
        memset(ops_arr, 0, sizeof(ops_arr));

        struct stack_i *val_stk=creat_i();
        struct stack_c *ops_stk=creat_c();

        int len = strlen(post_str);
        post_str[len] = ')';
        int cur = 0;

        push(ops_stk,'(');

        for (int i = 0; i <= len;) {
                if (isdigit(post_str[i])) {
                        int val = 0;
                        while (i < len && isdigit(post_str[i])) {
                                val = 10 * val + (post_str[i] - '0');
                                i++;
                        }
                        val_arr[cur++] = val;
                } 
                else {
                        if (post_str[i] == ')') {
                                while (!empty(ops_stk)&&top(ops_stk)!= '(' ) {
                                        ops_arr[cur++] =top(ops_stk);
                                        pop(ops_stk);
                                }
                                pop(ops_stk);
                        } else {
                                while (!empty(ops_stk) && (op_order(post_str[i],top(ops_stk)))) {
                                        /*
                                          栈顶运算符的优先级比读到的运算符的优先级高
                                          或二者相等，弹出栈顶运算符放入后缀表达式中
                                        */
                                        ops_arr[cur++] = top(ops_stk);
                                         pop(ops_stk);
                                }
                                push(ops_stk,post_str[i]);
                        }
                        i++;
                }
        }
        for (int i = 0; i < cur; i++) {
                if (!ops_arr[i]) {
                        push(val_stk,val_arr[i]);
                } else {
                        int v2 = top(val_stk);
                        pop(val_stk);
                        int v1 = top(val_stk);
                        pop(val_stk);
                        int val = calc(ops_arr[i], v1, v2);
                        push(val_stk,val);
                }
        }
        if(!Errno){
                printf("%d\n", top(val_stk));
        }else{
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
                                Errno=true;
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


int op_order(char c1,char c2)
{
        if(c1=='('||c2=='(')return 0;
        /*说明c2!='(,c2必然优先级大于等于c1*/
        if(c1=='+'||c1=='-')return 1;
        if(c1=='*'&&(c2=='*'||c2=='/'))return 1;
        if(c1=='/'&&(c2=='*'||c2=='/'))return 1;
        /*c1的优先级大于c2*/
        return 0;
}


void pop(struct stack_i * S)
{
    --S->Top;
}
void push(struct stack_i *S,int d)
{
    S->arr[++S->Top]=d;
}
int empty(struct stack_i *S)
{
    return S->Top==top_S;
}
struct stack_i *creat_i()
{
    struct stack_i *S;
    S=(struct stack_i *)malloc(sizeof(struct stack_i));
    S->arr=(int*)malloc(sizeof(int)*N);
    S->Top=top_S;
    return S;
}
int top(struct stack_i *S)
{
    return S->arr[S->Top];
}


void pop(struct stack_c * S)
{
    --S->Top;
}
void push(struct stack_c *S,int d)
{
    S->arr[++S->Top]=d;
}
int empty(struct stack_c *S)
{
    return S->Top==top_S;
}
struct stack_c *creat_c()
{
    struct stack_c *S;
    S=(struct stack_c *)malloc(sizeof(struct stack_c));
    S->arr=(char*)malloc(sizeof(char)*N);
    S->Top=top_S;
    return S;
}

char top(struct stack_c *S)
{
    return S->arr[S->Top];
}