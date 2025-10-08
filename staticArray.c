#include <stdio.h>
#define MAX 5000

void traverseArray(int a[],int n)
{
    printf("\nArray Elements : ");
    for(int i = 0; i < n; i++)
    {
        printf("[%d] ", a[i]);
    }
}

void insertElement(int arr[],int *n,int pos,int value,int capacity)
{
    if (*n >= capacity)
    {
        printf("Insertion failed! Array is full.\n");
        return;
    }
    if (pos<0 || pos>*n)
    {
        printf("Invalid position!\n");
        return;
    }

    for (int i=*n;i>pos;i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    (*n)++;

    printf("\nInserted %d at position %d successfully.\n", value, pos);

    printf("Updated Array: ");
    for (int i = 0;i<*n;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void deleteElement(int arr[], int *n, int pos)
{
    if (*n<=0)
    {
        printf("Deletion failed! Array is empty.\n");
        return;
    }
    if (pos<0 || pos>=*n)
    {
        printf("Invalid position!\n");
        return;
    }

    int deleted=arr[pos];

    for (int i=pos;i < *n-1; i++)
    {
        arr[i]=arr[i + 1];
    }

    (*n)--;

    printf("\nDeleted element %d from position %d successfully.\n", deleted, pos);

    printf("Updated Array: ");
    for (int i = 0;i<*n;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int searchKey(int a[],int n,int key)
{
    for(int i = 0;i<n;i++)
    {
        if(a[i] == key)
        {
            return i;
        }
    }
    return -1;
}

void sortArray(int a[],int n,int order)
{
    for(int i = 0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            int swap = 0;
            if(order == 1)
            {
                if(a[j] > a[j+1])
                {
                    swap=1;
                }
            }
            else if(order == 2) 
            {
                if(a[j] < a[j+1])
                {
                    swap = 1;
                }
            }

            if(swap)
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    if(order == 1)
    {
        printf("Array sorted in ascending order.\n");
    }
    else if(order == 2)
    {
        printf("Array sorted in descending order.\n");
    }
}

void displayArray(int a[], int n)
{
    if(n == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    printf("\nArray Elements: ");
    for(int i = 0;i<n;i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int arr[MAX];
    int n, pos, value, order, choice;

    printf("Enter total number of elements: ");
    scanf("%d", &n);

    for(int i = 0;i<n;i++)
    {
        printf("Enter element [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("\n========= ARRAY MENU =========\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Sort Array\n");
        printf("4. Display Array\n");
        printf("5. Search Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                printf("Enter position (0 to %d): ", n);
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &value);
                insertElement(arr, &n, pos, value, MAX);
                break;
            }
            case 2:
            {
                printf("Enter position (0 to %d): ", n - 1);
                scanf("%d", &pos);
                deleteElement(arr, &n, pos);
                break;
            }
            case 3:
            {
                printf("1. Ascending\n2. Descending\nChoose order: ");
                scanf("%d", &order);
                if(order != 1 && order != 2)
                {
                    printf("Invalid order choice!\n");
                }
                else
                {
                    sortArray(arr, n, order);
                }
                break;
            }
            case 4:
            {
                displayArray(arr, n);
                break;
            }
            case 5:
            {
                printf("Enter element to search: ");
                scanf("%d", &value);
                int index = searchKey(arr, n, value);
                if(index != -1)
                {
                    printf("Element found at index: %d\n", index);
                }
                else
                {
                    printf("Element not found.\n");
                }
                break;
            }
            case 6:
            {
                printf("\nExiting program...\n");
                break;
            }
            default:
            {
                printf("\nInvalid choice! Try again.\n");
            }
        }

    } while (choice != 6);

    return 0;
}
