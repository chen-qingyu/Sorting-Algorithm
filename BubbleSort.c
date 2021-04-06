#include "Sort.h"

void bubbleSort(item_t arr[], int n)
{
    int flag;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                item_t tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = 1; // Identity swapped
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}
