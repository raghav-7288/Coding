#include <bits/stdc++.h>
using namespace std;
int findLen(int freq)
{
    if (freq <= 1)
    {
        return freq;
    }

    int sol = 1;
    while (freq > 0)
    {
        sol++;
        freq /= 10;
    }
    return sol;
}
int shortestRunLengthEncoding(string s, int k)
{
    int n = s.size();
    if (n == k)
        return 0;
    if (n < k)
        return -1;
    s = "#" + s + "$";
    vector<int> leftLength(n + 2, 0), rightLength(n + 2, 0);
    int currLen = 0, currFreq = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] != s[i - 1])
        {
            currLen += findLen(currFreq);
            currFreq = 1;
            leftLength[i] = currLen + findLen(currFreq);
        }
        else
        {
            currFreq++;
            leftLength[i] = currLen + findLen(currFreq);
        }
    }
    currLen = currFreq = 0;
    for (int i = n; i >= 1; i--)
    {

        if (s[i] != s[i + 1])
        {
            currLen += findLen(currFreq);
            currFreq = 1;
            rightLength[i] = currLen + findLen(currFreq);
        }
        else
        {
            currFreq++;
            rightLength[i] = currLen + findLen(currFreq);
        }
    }

    vector<int> leftSameCharFreq(n + 2), rightSameCharFreq(n + 2);
    leftSameCharFreq[0] = 1;
    for (int i = 1; i <= n + 1; i++)
    {
        leftSameCharFreq[i] = (s[i] == s[i - 1] ? leftSameCharFreq[i - 1] + 1 : 1);
    }
    rightSameCharFreq[n + 1] = 1;
    for (int i = n; i >= 0; i--)
    {
        rightSameCharFreq[i] = (s[i] == s[i + 1] ? rightSameCharFreq[i + 1] + 1 : 1);
    }
    int minLength = INT_MAX / 2;
    for (int i = 1; i <= n - k + 1; i++)
    {
        if (s[i - 1] == s[i + k])
        {
            int remStrLen = leftLength[i - 1] + rightLength[i + k] - findLen(leftSameCharFreq[i - 1]) - findLen(rightSameCharFreq[i + k]) +
                            findLen(leftSameCharFreq[i - 1] + rightSameCharFreq[i + k]);
            minLength = min(minLength, remStrLen);
        }
        else
        {
            int remStrLen = leftLength[i - 1] + rightLength[i + k];
            minLength = min(minLength, remStrLen);
        }
    }

    return minLength;
}
int main()
{
    string str = "AAAAAAAAAAABXXAAAAAAAAAA";
    int k = 3;
    cout << shortestRunLengthEncoding(str, k);
    return 0;
}
