#include <stdio.h>
#define MAX 500
void bubbleSort(int arr[], int n) 
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int arr[MAX];
    int n;
    printf("Enter total number of elements :");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("Enter element [%d] :",i+1);
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr,n);
    for(int i=0;i<n;i++)
    {
        printf("[%d] ",arr[i]);
    }
    return 0;
}