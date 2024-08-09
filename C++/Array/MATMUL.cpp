#include <bits/stdc++.h>
using namespace std;

int main()
{
  int r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;
  vector<vector<int>> mat1(r1, vector<int>(c1, 0));
  vector<vector<int>> mat2(r2, vector<int>(c2, 0));
  vector<vector<int>> res(r1, vector<int>(c2, 0));
  for (int i = 0; i < r1; i++)
  {
    for (int j = 0; j < c1; j++)
    {
      cin >> mat1[i][j];
    }
  }
  for (int i = 0; i < r2; i++)
  {
    for (int j = 0; j < c2; j++)
    {
      cin >> mat2[i][j];
    }
  }
  if (c1 != r2)
  {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < r1; i++)
  {
    for (int j = 0; j < c2; j++)
    {
      res[i][j] = 0;
      for (int k = 0; k < r2; k++)
      {
        res[i][j] += (mat1[i][k] * mat2[k][j]);
      }
    }
  }
  for (int i = 0; i < r1; i++)
  {
    for (int j = 0; j < c2; j++)
    {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
}
