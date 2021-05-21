#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack_i{
    int Top;
    int * arr;
};
struct stack_c{
    int Top;
    char *arr;
};

#define N 1000010
#define top_S (-1)

void pop(struct stack_i * S);
void push(struct stack_i *S,int d);
int empty(struct stack_i *S);
struct stack_i *creat_i();

void pop(struct stack_c * S);
void push(struct stack_c *S,int d);
int empty(struct stack_c *S);
struct stack_c *creat_c();



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
struct stack_i *creat()
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