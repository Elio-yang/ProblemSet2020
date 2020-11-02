#include <cstdio>
#include <iostream>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>

struct stack
{
        int Cap;
        int Top;
        int *arr;
};
#define N 200100
#define top_S (-1)
void pop(struct stack *S);
void push(struct stack *S, int d);
int isEmpty(struct stack *S);
struct stack *creat();

#define belong_ops(str) ((str == '+') || (str == '-') || (str == '*' || (str == '/')))
#define belong_lbrac(str) ((str == '('))
#define belong_rbrac(str) ((str == ')'))
#define belong_brac(str) (belong_lbrac(str) || belong_rbrac(str))
#define order(op) ({int m;                      \
                    if(op=='+'||op=='-'){       \
                        m=1;                    \
                    }                           \
                    else if(op=='*'||op=='/'){  \
                        m=2;                    \
                    }                           \
                    else if(op=='('){           \
                        m=0;                    \
                    }                           \
                    m; })

using namespace std;

char *mid_to_post(const char *post_str, struct stack *val_s, struct stack *op_s);
void calc(char ops,int op1,int op2,struct stack *val_s);

int main()
{
        struct stack *op_s=creat();
        struct stack *val_s=creat();



        return 0;
}




int top(struct stack *S)
{
        if (!isEmpty(S))
        {
                return S->arr[S->Top];
        }
}
void pop(struct stack *S)
{
        if (isEmpty(S))
        {
                printf("invalid\n");
        }
        else
        {
                S->Top--;
        }
}

void push(struct stack *S, int d)
{
        S->arr[++S->Top] = d;
}
int isEmpty(struct stack *S)
{
        return S->Top == top_S;
}
struct stack *creat()
{
        struct stack *S;
        S = (struct stack *)malloc(sizeof(struct stack));
        S->arr = (int *)malloc(sizeof(int) * N);
        S->Cap = N;
        S->Top = top_S;
        return S;
}

char *mid_to_post(const char *post_str, struct stack *val_s, struct stack *op_s)
{
        int len = strlen(post_str);
        int val = 0;
        for (int i = 0; i < len; i++)
        {
                char c = post_str[i];

                if (isdigit(c))
                {
                        val = 10 * val + (c - '0');
                }
                else if (!isdigit(c))
                {
                        if(isdigit(post_str[i-1])){
                                push(val_s, val);
                        }
                        if (belong_ops(c))
                        {
                                if (isEmpty(op_s))
                                {
                                        push(op_s, c);
                                }
                                else
                                {
                                        if (order(c) > order(top(op_s)))
                                        {
                                                push(op_s, c);
                                        }
                                        else
                                        {
                                                char ops = top(op_s);
                                                int op2 = top(val_s);
                                                pop(val_s);
                                                int op1 = top(val_s);
                                                pop(val_s);
                                                calc(ops,op1,op2,val_s);
                                        }
                                        i--;
                                }
                        }
                        else if (belong_brac(c))
                        {
                                if (belong_lbrac(c))
                                {
                                        push(op_s, c);
                                }
                                else if (belong_rbrac(c))
                                {
                                        while ((char)top(op_s) != ')')
                                        {
                                                char ops = (char)top(op_s);
                                                int op2 = top(val_s);
                                                pop(val_s);
                                                int op1 = top(val_s);
                                                pop(val_s);
                                                calc(ops,op1,op2,val_s);
                                                pop(op_s);
                                        }
                                }
                        }
                }
        }
        while (!isEmpty(op_s))
        {
                char ops = (char)top(op_s);
                int op2 = top(val_s);
                pop(val_s);
                int op1 = top(val_s);
                pop(val_s);
                calc(ops,op1,op2,val_s);
                pop(op_s);
        }

}

void calc(char ops,int op1,int op2,struct stack *val_s)
{
        switch (ops)
                {
                case '+':
                {
                        int ans = op1 + op2;
                        push(val_s, ans);
                        break;
                }
                case '-':
                {
                        int ans = op1 - op2;
                        push(val_s, ans);
                        break;
                }
                case '*':
                {
                        int ans = op1 * op2;
                        push(val_s, ans);
                        break;
                }
                case '/':
                {
                        if (op2 == 0)
                        {
                                printf("ILLEGAL\n");
                                exit(0);
                        }
                        else
                        {
                                double ans = op1 / op2;
                                int val;
                                if(ans<0){
                                        val=ceil(ans);
                                }else{
                                        val=floor(ans);
                                }
                                /*向上取整 ceil
                                  向下取整 floor
                                  四舍五入 round
                                */
                                push(val_s, val);
                        }
                        break;
                }
                }
}