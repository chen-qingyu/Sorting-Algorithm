#include "Sort.h"

int* Sedgewick(int n)
{
    static int sedgewick[Sedgewick_SIZE] = {0};
    for (int i = 0; i < Sedgewick_SIZE; i += 2)
    {
        sedgewick[i] = 9 * pow(4, i) - 9 * pow(2, i) + 1;
        sedgewick[i + 1] = pow(4, i + 2) - 3 * pow(2, i + 2) + 1;
    }
    return sedgewick; // {s[0]=1, s[1]=5, s[2]=19, s[3]=41, ..., s[Sedgewick_SIZE-1]}
}

void shellSort(item_t arr[], int n)
{
    int* sedgewick = Sedgewick(n);

    int i, j, si;
    item_t tmp;

    for (si = Sedgewick_SIZE - 1; sedgewick[si] >= n; si--)
        ;

    for (int step = sedgewick[si]; si != -1; step = sedgewick[--si])
    {
        for (i = step; i < n; i++)
        {
            tmp = arr[i];
            for (j = i; j >= step && arr[j - step] > tmp; j -= step)
            {
                arr[j] = arr[j - step];
            }
            arr[j] = tmp;
        }
    }
}
