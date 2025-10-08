#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev; 
} Node;

Node* createNode(int data)
{
    Node* newNode = (Node *)malloc(sizeof(Node));
    if(!newNode)
    {
        printf("\nMemory Allocation Failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;  
    return newNode;
}

Node* insertAtFirst(Node* head, int data)
{
    Node* newNode = createNode(data);
    if(!head)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;  // Set previous pointer of old head
        head = newNode;
    }
    printf("\nInserted Successfully\n");
    return head;
}

Node* insertAtLast(Node* head, int data)
{
    Node* newNode = createNode(data);
    Node* temp = head;
    if(!head)
    {
        head = newNode;
    }
    else
    {
        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;  // Set previous pointer of new node
    }
    printf("\nInserted Successfully\n");
    return head;
}

int count(Node *head)
{
    int nodeCount = 0;
    while(head != NULL)
    {
        nodeCount++;
        head = head->next;
    }
    return nodeCount;
}

Node* insertAtPosition(Node* head, int data, int index)
{
    if(head == NULL)
    {
        printf("\nLinked List is empty\n");
    }
    else if(index >= count(head) + 1 || index < 0)
    {
        printf("\nInvalid Index! Valid range (0 to %d)\n", count(head));
    }
    else
    {
        Node* newNode = createNode(data);
        Node* temp = head;
        int position = 0;
        while(position < index - 1)
        {
            position++;
            temp = temp->next;
        }
        newNode->next = temp->next;
        if(temp->next) 
            temp->next->prev = newNode;  // Set previous pointer of next node
        temp->next = newNode;
        newNode->prev = temp;  // Set previous pointer of new node
        printf("\nInserted Successfully\n");
    }
    return head;
}

Node* deleteAtPosition(Node* head, int index)
{
    int position = 0;
    Node* temp = head;
    Node* temp2 = NULL;
    if(head == NULL)
    {
        printf("Linked List is empty\n");
    }
    else if(index < 0 || index > count(head) - 1)
    {
        printf("Invalid Index! Valid range (0 to %d)\n", count(head) - 1);
    }
    else
    {
        while(position < index)
        {
            position++;
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = temp->next;  // Remove node
        if(temp->next) 
            temp->next->prev = temp2;  // Set previous pointer of next node
        free(temp);
        printf("\nDeleted Successfully\n");
    }
    return head;
}

Node* deleteAtFirst(Node* head)
{
    Node* temp = head;
    if(!head)
    {
        printf("\nList Is Empty\n");
        return NULL;
    }
    else if(!head->next)
    {
        free(temp);
        printf("\nDeleted Successfully\n");
        return NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;  // Set previous of new head to NULL
        free(temp);
        printf("\nDeleted Successfully\n");
    }
    return head;
}

Node* deleteAtLast(Node* head)
{
    Node* temp = head;
    Node* tail = NULL;
    if(!head)
    {
        printf("\nList Is Empty\n");
        return NULL;
    }
    else
    {
        while(temp->next)
        {
            tail = temp;
            temp = temp->next;
        }
        tail->next = NULL;  // Remove the last node
        free(temp);
        printf("\nDeleted Successfully\n");
    }
    return head;
}

Node* reverseList(Node* head)
{
    Node* temp = head;
    Node* fast = NULL;
    Node* slow = NULL;
    if(head == NULL)
    {
        printf("\nLinked List is empty\n");
    }
    else
    {
        while(temp != NULL)
        {
            fast = temp->next;
            temp->next = slow;
            if(slow)
                slow->prev = temp;  // Set previous pointer of slow node
            slow = temp;
            temp = fast;
        }
        head = slow;
        printf("\nReversed Successfully\n");
    }
    return head;
}

void displayList(Node* head)
{
    if(!head)
    {
        printf("\nNothing to display\n");
    }
    else
    {
        while(head)
        {
            printf("[%d] <-> ", head->data);  // Display in doubly linked style
            head = head->next;
        }
        printf("NULL");
    }
}

int main()
{
    int data, choice, pos;
    Node* head = NULL;
    do
    {
        printf("\n\tMENU\t\n");
        printf("1.)Insert At First\n");
        printf("2.)Insert At Last\n");
        printf("3.)Delete At First\n");
        printf("4.)Delete At Last\n");
        printf("5.)Insert At Position\n");
        printf("6.)Delete At Position\n");
        printf("7.)Reverse List\n");
        printf("8.)Number of Nodes\n");
        printf("9.)Display Linked List\n");
        printf("10.)Exit\n");
        printf("Enter your choice :");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: printf("Enter data to insert :");
                    scanf("%d", &data);
                    head = insertAtFirst(head, data); break;

            case 2: printf("Enter data to insert :");
                    scanf("%d", &data);
                    head = insertAtLast(head, data); break;

            case 3: head = deleteAtFirst(head); break;

            case 4: head = deleteAtLast(head); break;

            case 5: printf("Enter data to insert :");
                    scanf("%d", &data);
                    printf("Enter position :");
                    scanf("%d", &pos);
                    head = insertAtPosition(head, data, pos); break;

            case 6: printf("Enter position to delete :");
                    scanf("%d", &pos);
                    head = deleteAtPosition(head, pos); break;

            case 7: head = reverseList(head); break;

            case 8: printf("\nTotal Number of Nodes :%d\n", count(head)); break;

            case 9: displayList(head); break;

            case 10: printf("\nExiting...\n"); break;

            default: printf("\nInvalid Input! Please enter a valid input (1,10)\n");
        }
    } while(choice != 10);

    return 0;
}