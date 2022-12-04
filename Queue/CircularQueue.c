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

struct queue *CQ;

void Initialize(struct queue *CQ)
{
    CQ->front=0;
    CQ->rear=-1;
}

int IsEmpty(struct queue *CQ)
{
    if(CQ->front - CQ->rear+1==0)
        return TRUE;
    else
        return FALSE;
}

char EnQueue(struct queue *CQ,char x)
{
    if((CQ->rear + 1) % QSIZE == CQ->front){
        printf("queue overflows");
        exit(1);
    }
    CQ->rear= (CQ->rear+1) % QSIZE;
    CQ->item[CQ->rear]=x;
    return x;
}

char DeQueue(struct queue *CQ)
{
    char x;
    if(IsEmpty(CQ)){
        printf("queue underflows");
        exit(1);
    }
    CQ->front= (CQ->front+1) % QSIZE;
    x= CQ->item[CQ->front];
    return x;
}

int queueTop(struct queue *CQ)
{
    int x= CQ->item[CQ->front];
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