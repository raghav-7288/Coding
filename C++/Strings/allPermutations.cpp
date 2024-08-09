#include <bits/stdc++.h>
using namespace std;

void per(string mess, int start, int end)
{
  if (start == end-1)
  {
    // st.insert(mess);
    cout << mess << endl;
    return;
  }
  for (int i = start; i < end; i++)
  {
    swap(mess[start], mess[i]);
    per(mess, start + 1, end);
    swap(mess[start], mess[i]);
  }
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  // unordered_set<string> st;
  string mess;
  cin >> mess;
  int n = mess.length();
  per(mess, 0, n);
  // for (auto val : st)
  // {
  //   cout << val << endl;
  // }
  return 0;
}
