#include <bits/stdc++.h>
using namespace std;
void disp1D(vector<int> test)
{
    for (auto i = test.begin(); i != test.end(); i++)
    {
        cout << *(i) << " ";
    }
}
void disp2D(vector<vector<int>> test)
{
    for (auto i = test.begin(); i != test.end(); i++)
    {
        for (auto j = i->begin(); j != i->end(); j++)
        {
            cout << *(j) << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> a(5, vector<int>(5, 0));
    vector<vector<int>>::iterator i1;
    vector<int>::iterator i;
    disp2D(a);
    return 0;
}