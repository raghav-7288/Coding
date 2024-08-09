#include <bits/stdc++.h>
using namespace std;
void radixSort(int n,int currD ,int d, vector<int> &arr)
{
    if(currD==d){
        return;
    }
    

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    radixSort(n, 0, d, arr);
    for (auto x : arr)
    {
        cout << x << " ";
    }

    return 0;
}