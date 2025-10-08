#include <stdio.h>

int binarySearch(int arr[], int l, int r, int key) 
{
    while (l <= r) 
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == key) 
        {
            return mid;
        } 
        else if (arr[mid] < key) 
        {
            l = mid + 1;
        } 
        else 
        {
            r = mid - 1;
        }
    }
    return -1;
}

int main() 
{
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements in sorted order:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1)
    {
        printf("Element found at index %d\n", result);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}
