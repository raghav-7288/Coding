#include <bits/stdc++.h>
using namespace std;
void Permute(vector<int> &a, int index, int n, vector<vector<int>> &allPerm)
{
  if (index == n - 1)
  {
    allPerm.push_back(a);
    return;
  }
  for (int i = index; i < n; i++)
  {
    swap(a[index], a[i]);
    Permute(a, index + 1, n, allPerm);
    swap(a[index], a[i]);
  }
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
  vector<vector<int>> allPerms;
  Permute(a, 0, n, allPerms);
  for (auto x : allPerms)
  {
    for (auto y : x)
    {
      cout << y << " ";
    }
    cout << endl;
  }

  return 0;
}