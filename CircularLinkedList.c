#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;  
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
    newNode->next = newNode; 
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
        Node* temp = head;
        while(temp->next != head)  
        {
            temp = temp->next;
        }
        temp->next = newNode;  
        newNode->next = head;  
        head = newNode;  
    }
    printf("\nInserted Successfully\n");
    return head;
}

Node* insertAtLast(Node* head, int data)
{
    Node* newNode = createNode(data);
    if(!head)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;
        while(temp->next != head)  
        {
            temp = temp->next;
        }
        temp->next = newNode;  
        newNode->next = head;  
    }
    printf("\nInserted Successfully\n");
    return head;
}

Node* deleteAtFirst(Node* head)
{
    if(!head)
    {
        printf("\nList Is Empty\n");
        return NULL;
    }
    else if(head->next == head)  
    {
        free(head);
        printf("\nDeleted Successfully\n");
        return NULL;
    }
    else
    {
        Node* temp = head;
        Node* last = head;
        while(last->next != head)  
        {
            last = last->next;
        }
        head = head->next;  
        last->next = head;  
        free(temp);
        printf("\nDeleted Successfully\n");
    }
    return head;
}

Node* deleteAtLast(Node* head)
{
    if(!head)
    {
        printf("\nList Is Empty\n");
        return NULL;
    }
    else if(head->next == head)  
    {
        free(head);
        printf("\nDeleted Successfully\n");
        return NULL;
    }
    else
    {
        Node* temp = head;
        while(temp->next != head)  
        {
            temp = temp->next;
        }
        Node* last = temp->next;  
        temp->next = head;  
        free(last);
        printf("\nDeleted Successfully\n");
    }
    return head;
}

int count(Node *head)
{
    int nodeCount = 0;
    if(head != NULL)
    {
        Node* temp = head;
        do
        {
            nodeCount++;
            temp = temp->next;
        } while(temp != head);  
    }
    return nodeCount;
}

Node* insertAtPosition(Node* head, int data, int index)
{
    if(head == NULL)
    {
        printf("\nLinked List is empty\n");
    }
    else if(index < 0 || index > count(head))
    {
        printf("\nInvalid Index! Valid range (0 to %d)\n", count(head));
    }
    else if(index == 0)
    {
        head = insertAtFirst(head, data);  
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
        temp->next = newNode;  
    }
    printf("\nInserted Successfully\n");
    return head;
}

Node* deleteAtPosition(Node* head, int index)
{
    int position = 0;
    Node* temp = head;
    if(head == NULL)
    {
        printf("Linked List is empty\n");
    }
    else if(index < 0 || index >= count(head))
    {
        printf("Invalid Index! Valid range (0 to %d)\n", count(head) - 1);
    }
    else if(index == 0)
    {
        head = deleteAtFirst(head);  
    }
    else
    {
        Node* temp2 = NULL;
        while(position < index - 1)  
        {
            position++;
            temp = temp->next;
        }
        temp2 = temp->next;  
        temp->next = temp2->next;  
        free(temp2);
        printf("\nDeleted Successfully\n");
    }
    return head;
}

Node* reverseList(Node* head)
{
    if(!head)
    {
        printf("\nLinked List is empty\n");
        return head;
    }

    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    do
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while(current != head);

    head->next = prev;  
    head = prev;  
    printf("\nReversed Successfully\n");
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
        Node* temp = head;
        do
        {
            printf("[%d] -> ", temp->data);
            temp = temp->next;
        } while(temp != head);  
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