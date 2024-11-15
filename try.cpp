#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod = 1e9 + 7;
int binaryToInt(const string &binary)
{
    return stoi(binary, nullptr, 2);
}
double euclideanDistance(int r1, int g1, int b1, int r2, int g2, int b2)
{
    return sqrt(pow(r1 - r2, 2) + pow(g1 - g2, 2) + pow(b1 - b2, 2));
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    map<string, tuple<int, int, int>> pix;
    pix["Red"] = make_tuple(255, 0, 0);
    pix["Black"] = make_tuple(0, 0, 0);
    pix["White"] = make_tuple(255, 255, 255);
    pix["Green"] = make_tuple(0, 255, 0);
    pix["Blue"] = make_tuple(0, 0, 255);
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        int r = binaryToInt(s.substr(0, 8));
        int g = binaryToInt(s.substr(8, 8));
        int b = binaryToInt(s.substr(16, 8));
        string closestColor = "";
        double minDistance = DBL_MAX;
        int minCount = 0;
        for (auto color : pix)
        {
            auto [cr, cg, cb] = color.second;
            double distance = euclideanDistance(r, g, b, cr, cg, cb);

            if (distance < minDistance)
            {
                minDistance = distance;
                closestColor = color.first;
                minCount = 1;
            }
            else if (distance == minDistance)
            {
                minCount++;
            }
        }
        if (minCount > 1)
        {
            cout << "Ambiguous" << endl;
        }
        else
        {
            cout << closestColor << endl;
        }
    }
    return 0;
}
