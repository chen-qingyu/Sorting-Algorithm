#include "Sort.h"

int main(void)
{
    item_t arr[SIZE];
    int n = 0;
    printf("Please input the data to be sorted:\n");
    while (n < SIZE && scanf("%lf", &arr[n]))
    {
        n++;
        if (getchar() == '\n')
        {
            break;
        }
    }

    quickSort(arr, n);

    printf("\n");
    printf("The sorted data are as follows:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%3d : %9.2lf\n", i + 1, arr[i]);
    }

    return 0;
}
