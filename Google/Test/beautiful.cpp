#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    string res = S;
    auto can_place = [&](int i, char c) -> bool
    {
        if (i > 0 && res[i - 1] == c)
            return false;
        if (i > 1 && res[i - 2] == c)
            return false;
        return true;
    };
    int pos = N - 1;
    while (pos >= 0)
    {
        char current_char = res[pos];
        for (char c = current_char + 1; c < 'a' + K; c++)
        {
            if (can_place(pos, c))
            {
                res[pos] = c;
                bool valid = true;
                for (int j = pos + 1; j < N; j++)
                {
                    bool placed = false;
                    for (char ch = 'a'; ch < 'a' + K; ch++)
                    {
                        if (can_place(j, ch))
                        {
                            res[j] = ch;
                            placed = true;
                            break;
                        }
                    }
                    if (!placed)
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                {
                    cout << res;
                    return 0;
                }
            }
        }
        pos--;
    }
    cout << "-1";
    return 0;
}
