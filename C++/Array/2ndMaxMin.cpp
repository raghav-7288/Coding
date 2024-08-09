// int print2largest(vector<int> &arr) {
//     int n=arr.size();
//     int sL,L=arr[0];
//     for(int i=0;i<n;i++){
//         if(arr[i]>L) {sL=L;L=arr[i];}
//         if(arr[i]<L && arr[i]>sL) sL=arr[i];
//     }
//     return sL;
// }
#include <bits/stdc++.h>
using namespace std;
int secondLargest(vector<int> a)
{
    int largest = a[0];
    int slargest = INT_MIN;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] > largest)
        {
            slargest = largest;
            largest = a[i];
        }
        else if (a[i] < largest && a[i] > slargest)
        {
            slargest = a[i];
        }
    }
    return slargest;
}
int secondSmallest(vector<int> a)
{
    int smallest = a[0];
    int ssmallest = INT_MAX;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] < smallest)
        {
            ssmallest = smallest;
            smallest = a[i];
        }
        else if (a[i] > smallest && a[i] < ssmallest)
        {
            ssmallest = a[i];
        }
    }
    return ssmallest;
}
int main()
{
    vector<int> a = {1, 4, 7, 2, 9, 3, 6, 8, 8, 9, -1};
    int slargest = secondLargest(a);
    int ssmallest = secondSmallest(a);

    cout << ssmallest << " " << slargest;

    return 0;
}