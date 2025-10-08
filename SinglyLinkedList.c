#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
}Node;

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

Node* insertAtFirst(Node* head,int data)
{
    Node* newNode=createNode(data);
    if(!head)
    {
        head=newNode;
        
    }
    else
    {
        newNode->next=head;
        head=newNode;
    }
    printf("\nInserted Successfully\n");
    return head;
}

Node* insertAtLast(Node* head,int data)
{
    Node* newNode=createNode(data);
    Node* temp=head;
    if(!head)
    {
        head=newNode;
    }
    else
    {
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
    printf("\nInserted Successfully\n");
    return head;
}