#include <stdio.h>
#include "isort.h"

int main()
{
    int num_from_user;
    int arr[SIZE];

    // Gets 50 numbers from the user
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &num_from_user);
        *(arr + i) = num_from_user;
    }

    // Sorts the array's numbers
    insertion_sort(arr, SIZE);

    // Prints the array's numbers
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", *(arr + i));
    }
    return 0;
}