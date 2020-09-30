#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    int Cap;
    int Top;
    int * arr;
};
#define N 20010
#define top_S (-1)
void pop(struct stack * S);
void push(struct stack *S,int d);
int isEmpty(struct stack *S);
struct stack *creat();

int main()
{
    /*第一行*/
    int n;
    scanf("%d",&n);
    struct stack *S=creat();
    int op1;
    int d;
    char * out[N];
    for(int i=0;i<n;i++){
        scanf("%d",&op1);
        if(op1==1){
            scanf("%d",&d);
            push(S,d);
        }
        else if(op1==0){
            pop(S);
        }
    }
    system("pause");
    return 0;
}

void pop(struct stack * S)
{
    if(isEmpty(S)){
        printf("invalid\n");
    }else{
        printf("%d\n",S->arr[S->Top--]);
    }
}
void push(struct stack *S,int d)
{
    S->arr[++S->Top]=d;
}
int isEmpty(struct stack *S)
{
    return S->Top==top_S;
}
struct stack *creat()
{
    struct stack *S;
    S=(struct stack *)malloc(sizeof(struct stack));
    S->arr=(int*)malloc(sizeof(int)*N);
    S->Cap=N;
    S->Top=top_S;
    return S;
}