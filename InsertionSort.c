#include "Sort.h"

void insertionSort(item_t arr[], int n)
{
    int i, j;
    item_t tmp;
    for (i = 1; i < n; i++)
    {
        tmp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > tmp; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;
    }
}
