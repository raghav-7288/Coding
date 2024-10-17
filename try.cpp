#include <bits/stdc++.h>
using namespace std;
/*
Everything case insensitive
1.ignore leading a,an,the
2.ignore trailing {inc. , corp , llc , l.l.c. , llc.}
3.& , considered as spaces
4. multiple spaces is a single space
5.ignore and if it is in between
*/
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    cout << s << endl;
    int pos_name = s.find_first_of('|');
    cout << pos_name;
    return 0;
}