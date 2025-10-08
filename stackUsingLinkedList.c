#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *next;
} stack;

stack *createNode(int data) 
{
    stack *newNode = (stack *)malloc(sizeof(stack));
    if (!newNode) 
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

stack *pushInStack(stack *top, int data) 
{
    stack *newNode = createNode(data);
    newNode->next = top;
    top = newNode;
    printf("\nPushed Successfully\n");
    return top;
}

stack *popInStack(stack *top) 
{
    if (top == NULL) 
    {
        printf("\nCan't pop! Stack is empty.\n");
        return top;
    }
    stack *temp = top;
    top = top->next;
    printf("\nPopped Element: %d\n", temp->data);
    free(temp);
    return top;
}

int peekElement(stack *top) 
{
    if (top == NULL) 
    {
        printf("\nStack is empty! Nothing to peek.\n");
        return -1;
    }
    printf("\nTop Element: %d\n", top->data);
    return top->data;
}

void displayStack(stack *top) {
    if (!top) 
    {
        printf("\nNothing to display\n");
        return;
    }
    printf("\n--- Stack Elements (Top to Bottom) ---\n");
    while (top) 
    {
        printf("|  %2d  |\n", top->data);
        top = top->next;
    }
    printf("-------------------------\n");
}

int main() 
{
    stack *top = NULL;
    int data, choice;

    do 
    {
        printf("\n---- STACK MENU ----\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                top = pushInStack(top, data);
                break;
            case 2:
                top = popInStack(top);
                break;
            case 3:
                peekElement(top);
                break;
            case 4:
                displayStack(top);
                break;
            case 5:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid Input! Try again...\n");
        }
    } while (choice != 5);

    return 0;
}
