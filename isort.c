#include <stdio.h>
#include "isort.h"

// Shifts i elements to the right
void shift_element(int *arr, int i)
{
    int temp = *(arr + i);

    for (int j = i - 1; j >= 0; j--)
    {
        *(arr + j + 1) = *(arr + j);
    }
    *arr = temp;
}

// Sorts the numbers using pointers (insertion sort)
void insertion_sort(int *arr, int len)
{
    int temp;

    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (*(arr + j) < *(arr + i))
            {
                temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}
