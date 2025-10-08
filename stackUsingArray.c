#include <stdio.h>
#define MAX 50000

int stack[MAX];
int top = -1;

void push() 
{
    if (top == MAX - 1) 
    {
        printf("Stack Overflow\n");
    } 
    else 
    {
        int element;
        printf("Enter the element: ");
        scanf("%d", &element);
        stack[++top] = element;
        printf("Element %d pushed to stack.\n", element);
    }
}

void pop() 
{
    if (top == -1) 
    {
        printf("Stack Underflow\n");
    }
    else 
    {
        printf("Popped element: %d\n", stack[top--]);
    }
}

void peek() 
{
    if (top == -1) 
    {
        printf("Stack is empty.\n");
    } 
    else 
    {
        printf("Top element: %d\n", stack[top]);
    }
}

void display() 
{
    if (top == -1) 
    {
        printf("Stack is empty.\n");
    } 
    else 
    {
        printf("Stack elements (top to bottom):\n");
        for (int i = top; i >= 0; i--) 
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main() 
{
    int choice;

    do 
    {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: printf("\nExiting...\n");break;
            default: printf("Invalid choice! Try again.\n");
        }
    }while(choice != 5);

    return 0;
}
