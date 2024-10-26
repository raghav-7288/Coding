#include <bits/stdc++.h>
using namespace std;

// Function to determine the earliest starting index where B is a subsequence of A
int find_subsequence_with_modification(const string &A, const string &B)
{
    int N = A.size();
    int M = B.size();
    if (M == 0)
        return 1; // Empty string B is always a subsequence
    if (N == 0)
        return -1; // Non-empty B cannot be a subsequence of empty A

    // Initialize pointers for two states
    int j0 = 0;      // State 0: without modification
    int j1 = 0;      // State 1: with modification
    int start0 = -1; // Starting index for State 0
    int start1 = -1; // Starting index for State 1
    int result = -1;

    for (int i = 0; i < N; i++)
    {
        // State 0: Without Modification
        if (j0 < M && A[i] == B[j0])
        {
            if (j0 == 0)
                start0 = i;
            j0++;
        }

        // State 1: With Modification
        if (j1 < M)
        {
            if (A[i] == B[j1])
            {
                if (j1 == 0)
                    start1 = i;
                j1++;
            }
            // Attempt to use modification if not already used and not the first character
            else if (j1 == j0 && i != 0)
            {
                // Use modification to match B[j1]
                if (j1 == 0)
                {
                    // Modification at the starting character is not allowed
                    // So skip modification at i=0
                }
                else
                {
                    if (j1 < M)
                    {
                        if (j1 == 0)
                        {
                            // Cannot modify the first character
                        }
                        else
                        {
                            // Modify current character to match B[j1]
                            if (start1 == -1)
                                start1 = start0; // Inherit starting index from State 0
                            j1++;
                        }
                    }
                }
            }
        }

        // Check if either state has fully matched B
        if (j0 == M)
        {
            // Found a match without modification
            result = start0 + 1; // Convert to 1-based indexing
            break;
        }
        if (j1 == M)
        {
            // Found a match with modification
            if (result == -1 || start1 + 1 < result)
            {
                result = start1 + 1;
            }
            break;
        }
    }

    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int I;
    cin >> I;

    while (I--)
    {
        string A, B;
        cin >> A >> B;

        int answer = find_subsequence_with_modification(A, B);
        cout << answer << "\n";
    }
    return 0;
}
