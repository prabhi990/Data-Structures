#include <stdio.h>
#include<stdlib.h>
#define QSIZE 10
#define TRUE 1
#define FALSE 0

struct queue
{
    int item[QSIZE];
    int front;
    int rear;
};

struct queue *Q;

void Initialize(struct queue *Q)
{
    Q->front=0;
    Q->rear=-1;
}

int IsEmpty(struct queue *Q)
{
    if(Q->front - Q->rear+1==0)
        return TRUE;
    else
        return FALSE;
}

char EnQueue(struct queue *Q,char x)
{
    if(Q->rear == QSIZE-1){
        printf("queue overflows");
        exit(1);
    }
    Q->rear= Q->rear+1;
    Q->item[Q->rear]=x;
    return x;
}

char DeQueue(struct queue *Q)
{
    char x;
    if(IsEmpty(Q)){
        printf("queue underflows");
        exit(1);
    }
     x= Q->item[Q->front];
    Q->front= Q->front-1;
    return x;
}

int queueTop(struct queue *Q)
{
    int x= Q->item[Q->front];
    return x;
}

int main()
{
    char x;
    struct queue MQ;
    Initialize(&MQ);
    EnQueue(&MQ,'A');
    EnQueue(&MQ,'B');
    EnQueue(&MQ,'C');
    EnQueue(&MQ,'D');
    EnQueue(&MQ,'E');
    EnQueue(&MQ,'F');
    char y = DeQueue(&MQ);
    printf("%c",y);
    return 0;
}