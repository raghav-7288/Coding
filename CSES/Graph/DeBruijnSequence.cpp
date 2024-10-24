#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod = 1e9 + 7;
void dfs(string node, int k, string s, unordered_map<string, int> &vis, vector<int> &edges)
{
    for (int i = 0; i < k; i++)
    {
        string temp = node + s[i];
        if (!vis[temp])
        {
            vis[temp] = 1;
            dfs(temp.substr(1), k, s, vis, edges);
            edges.push_back(i);
        }
    }
}
string dbs(int n, string &s)
{
    int k = s.length();
    vector<int> edges;
    unordered_map<string, int> vis;
    string start(n - 1, s[0]);
    dfs(start, k, s, vis, edges);

    string ans = "";
    int limit = pow(k, n);
    for (int i = 0; i < limit; i++)
    {
        ans += s[edges[i]];
    }
    ans += start;

    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    string s = "01";
    cout << dbs(n, s);
    return 0;
}