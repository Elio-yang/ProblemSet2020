#include <stdio.h>
#include <stdlib.h>

#define N 20010
struct queue *creat();
int isEmpty(struct queue *Q);
void enqueue(struct queue *Q,int d);
void dequeue(struct queue *Q);

struct queue{
    int front;
    int rear;
    int size;
    int * arr;
};

int main()
{
    int n;
    scanf("%d",&n);
    struct queue *Q=creat();
    int op1;
    int d;
    for(int i=0;i<n;i++){
        scanf("%d",&op1);
        if(op1==1){
            scanf("%d",&d);
            enqueue(Q,d); 
        }else{
            dequeue(Q);
        }
    }
    system("pause");
    return 0;
}

int isEmpty(struct queue *Q)
{
    return Q->size==0;
}
void enqueue(struct queue *Q,int d)
{
    ++Q->size;
    Q->arr[++Q->rear]=d;
}
void dequeue(struct queue *Q)
{
    if(isEmpty(Q)){
        printf("invalid\n");
    }else{
        --Q->size;
        printf("%d\n",Q->arr[Q->front++]);
    }
}
struct queue *creat()
{
    struct queue *Q=(struct queue*)malloc(sizeof(struct queue));
    Q->size=0;
    Q->arr=(int *)malloc(sizeof(int)*N);
    Q->front=1;
    Q->rear=0;
    return Q;
}