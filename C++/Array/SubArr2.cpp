#include <bits/stdc++.h>
using namespace std;
void genAllSubArr(int index, int n, vector<int> &a, vector<int> &currSubArr, vector<vector<int>> &allSubArr)
{
    if (index == n)
    {
        allSubArr.push_back(currSubArr);
        return;
    }
    currSubArr.push_back(a[index]);
    genAllSubArr(index + 1, n, a, currSubArr, allSubArr);
    currSubArr.pop_back();
    genAllSubArr(index + 1, n, a, currSubArr, allSubArr);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> allSubArr;
    vector<int> currSubArr;
    genAllSubArr(0, n, a, currSubArr, allSubArr);
    for (auto x : allSubArr)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}