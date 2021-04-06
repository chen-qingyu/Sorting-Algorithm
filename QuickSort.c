#include "Sort.h"

/*
����������������㷨�ļ��㣬����Ҫ˵��һ�£�
1. ������ο����й���ѧMOOC���ĳ�Խ��ʦ�Ŀγ�������һ��������ֵ CUTOFF �����������Ԫ���������������ֵʱ�Ž�����ţ�������ü������������õ�ѡ������ð������Ҳ���ԣ�����Ϊ���������Ƶ���ݹ飬���������Ԫ���������Сʱ������������ܻ����������졣
2. һ����˵�����ŵĲ��������������������Ԫ���׵�ַ�������ʼ�±ꡢ�ұ߽����±꣬���ϵĿ��ų����඼�������ġ������Ұ����򻯵��������������������Ԫ���׵�ַ���������Ԫ�ظ�������Ϊ���Ż�Ƶ���صݹ飬����ԭʼ�汾��push push push���� pop pop pop����������汾����push push���� pop pop�������ܵ���˵�����Ǽ����˴������֮һ�ĺ������ÿ�������һ��ʼ��Ϊ�����ӳ���ĸ��Ӷȣ����Ϳɶ��ԣ�����д��֮�����ƺ���û�н��Ϳɶ��ԣ�������˿��ŵĻ���ô�������Ӧ�û��Ǻ����׿����ġ����������պ÷��� void XXX_Sort(item_t arr[], int n) �����ĺ����ӿڣ��Ͳ���������дһ�����Ͻӿڵĺ���Ȼ���ٵ��õݹ��ˡ�
*/

void swap(item_t* a, item_t* b)
{
    item_t tmp = *a;
    *a = *b;
    *b = tmp;
}

item_t median(item_t arr[], int n)
{
    int left = 0, right = n - 1;
    int center = (left + right) / 2;

    if (arr[left] > arr[center])
    {
        swap(&arr[left], &arr[center]);
    }
    if (arr[left] > arr[right])
    {
        swap(&arr[left], &arr[right]);
    }
    if (arr[center] > arr[right])
    {
        swap(&arr[center], &arr[right]);
    }

    swap(&arr[center], &arr[right - 1]);

    return arr[right - 1];
}

void quickSort(item_t arr[], int n)
{
    if (n > CUTOFF)
    {
        int pivot, low, high;

        pivot = median(arr, n);
        low = 0;
        high = n - 2;

        while (1)
        {
            while (arr[++low] < pivot)
                ;
            while (arr[--high] > pivot)
                ;
            if (low < high)
            {
                swap(&arr[low], &arr[high]);
            }
            else
            {
                break;
            }
        }

        swap(&arr[low], &arr[n - 2]);

        quickSort(arr, low);
        quickSort(arr + low + 1, n - low - 1);
    }
    else
    {
        insertionSort(arr, n);
    }
}
