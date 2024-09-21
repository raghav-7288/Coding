#include <bits/stdc++.h>
using namespace std;
int main()
{

  int a = -1, b = -1;
  int n, k;
  cin >> n >> k;
  int c = n, d = k;
  while (d)
  {
    a *= (c--);
    b *= (d--);
  }
  cout << int(a / b);
  return 0;
}
