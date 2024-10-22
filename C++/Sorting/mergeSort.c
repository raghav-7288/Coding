#include <stdio.h>
void merge(int arr[], int s, int m, int e)
{
    int i, j, k;
    int n1 = m - s + 1, n2 = e - m;
    int left[n1], right[n2];
    for (i = 0; i < n1; i++)
    {
        left[i] = arr[s + i];
    }
    for (i = 0; i < n2; i++)
    {
        right[i] = arr[m + 1 + i];
    }
    i = 0;
    j = 0;
    k = s;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }
    while (i < n1)
    {
        arr[k++] = left[i++];
    }
    while (j < n2)
    {
        arr[k++] = right[j++];
    }
}
void mergeSort(int arr[], int s, int e)
{
    if (s < e)
    {
        int m = (s + e) / 2;
        mergeSort(arr, s, m);
        mergeSort(arr, m + 1, e);
        merge(arr, s, m, e);
    }
}
int main()
{
    int n, i;
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n - 1);
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}