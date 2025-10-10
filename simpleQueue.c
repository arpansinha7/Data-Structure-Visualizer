#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

typedef struct Queue
{
    Node* front;
    Node* rear;
}Queue;

Node* createNode(int data)
{
    Node* newNode=(Node *)malloc(sizeof(Node));
    if(!newNode)
    {
        printf("\nMemory Allocation Failed\n");
        exit(1);
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void enqueue(Queue* qhead,int data)
{
    Node* newNode=createNode(data);
    
    if(!qhead->rear)
    {
        qhead->front=qhead->rear=newNode;
    }
    else
    {
        qhead->rear->next=newNode;
        qhead->rear=newNode;
    }
}

void dequeue(Queue *qhead)
{
    if(!qhead->front)
    {
        printf("\nQueue is Empty\n");
        return;
    }
    Node* temp=qhead->front;
    qhead->front=qhead->front->next;
    int data=temp->data;
    if(qhead->front==NULL)
    {
        qhead->rear=NULL;
    }
    free(temp);
    printf("\nElement %d Dequeued\n",data);
}

int peek(Queue *qhead)
{
    if(!qhead || !qhead->front)
    {
        printf("\nQueue is empty\n");
        return -1;
    }
    return qhead->front->data;
}

int isEmpty(Queue* qhead)
{
    return (qhead->front==NULL);
}

void display(Queue *qhead)
{
    if(!qhead->front)
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        Node* temp=qhead->front;
        printf("\nQueue Elements :");
        while(temp)
        {
            printf("[%d] ",temp->data);
            temp=temp->next;
        }
    }
}

int main()
{
    Queue qhead;
    qhead.front=qhead.rear=NULL;

    int choice,data;

    do
    {
        printf("\n====== Queue Menu ======\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek (Front Element)\n");
        printf("4.Check if Empty\n");
        printf("5.Display Queue\n");
        printf("6.Exit\n");
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter value to enqueue :");
            scanf("%d",&data);
            enqueue(&qhead,data);
            printf("\nElement %d Enqueued\n",data);
            break;

            case 2:dequeue(&qhead);break;

            case 3:
            {
                int frontVal=peek(&qhead);
                if(frontVal==-1)
                {
                    printf("\nQueue is empty\n");
                }
                else
                {
                    printf("\nFront Element :%d\n",frontVal);
                }
                break;
            }    

            case 4: if(isEmpty(&qhead))
                    {
                        printf("\nQueue is empty\n");
                    }
                    else
                    {
                        printf("\nQueue is not empty\n");
                    }
                    break;
                    
            case 5:display(&qhead);break;

            case 6:printf("\nExiting program...\n");break;

            default:printf("\nInvalid Choice! Try Again\n");
        }
    } while (choice != 6);
    
    return 0;
}