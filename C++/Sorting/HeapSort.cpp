#include <bits/stdc++.h>
using namespace std;
void heapify(int pos, int size, int arr[])
{
    int lc = 2 * pos + 1;
    int rc = 2 * pos + 2;
    int larger = pos;
    if (lc < size && arr[larger] < arr[lc])
    {
        larger = lc;
    }
    if (rc < size && arr[larger] < arr[rc])
    {
        larger = rc;
    }
    if (larger != pos)
    {
        swap(arr[larger], arr[pos]);
        heapify(larger, size, arr);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    // int *arr;
    int n;
    cin >> n;
    int arr[n];
    // arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = n / 2 - 1; i > -1; i--)
    {
        heapify(i, n, arr);
    }
    for (int i = n - 1; i > -1; i--)
    {
        swap(arr[i], arr[0]);
        heapify(0, i, arr);
    }
    cout << "Sorted Array Is" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}