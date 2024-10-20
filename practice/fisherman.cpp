// #define _CRT_SECURE_NO_WARNINGS
// #include <bits/stdc++.h>
// using namespace std;
// #define MAX 3

// int fishspot[100];  // fishing spots
// int gate[MAX];      // position of gates
// int fishermen[MAX]; // no of fishermen at each gate
// int N;              // total no of fishing spots
// int visited[MAX];   // occupied fishing spots
// int Answer;         // result

// // To unmark spots occupied by fishermen of gate# index
// class GFG
// {
// public:
//     void reset_fishspot(int index)
//     {
//         int i;
//         for (i = 1; i <= N; i++)
//             if (fishspot[i] == index + 1)
//                 fishspot[i] = 0;
//     }

//     // Calculate minimum distance while
//     // allotting spots to fishermen of gate# index.
//     // Returns number of positions possible
//     // with minimum distance.
//     // pos1, pos2 is used to return positions
//     int calculate_distance(int index, int *pos1, int *pos2, int *score)
//     {
//         int i, sum = 0, left_min = 999999, right_min = 999999, left, right, npos = 0;
//         *pos1 = *pos2 = *score = 0;

//         left = right = gate[index];

//         // Allot spots to all fishermen except
//         // last based on minimum distance
//         for (i = 1; i < fishermen[index]; i++)
//         {
//             if (fishspot[gate[index]] == 0)
//             {
//                 sum++;
//                 fishspot[gate[index]] = index + 1;
//             }
//             else
//             {
//                 left_min = right_min = 999999;

//                 while ((left > 0) && (fishspot[left] > 0))
//                     left--;

//                 while ((right <= N) && (fishspot[right] > 0))
//                     right++;

//                 if ((left > 0) && (fishspot[left] == 0))
//                     left_min = gate[index] - left + 1;

//                 if ((right <= N) && (fishspot[right] == 0))
//                     right_min = right - gate[index] + 1;

//                 if (right_min == left_min)
//                 {
//                     // Place 2 fishermen, if available
//                     if ((fishermen[index] - i - 1) > 1)
//                     {
//                         fishspot[left] = fishspot[right] = index + 1;
//                         sum += (2 * left_min);
//                         i++;

//                         // If all fishermen are alloted spots
//                         if (i == fishermen[index])
//                         {
//                             npos = 1;
//                             *score = sum;
//                             return npos;
//                         }
//                     }
//                     else
//                     {
//                         sum += left_min;
//                         fishspot[left] = index + 1;
//                     }
//                 }
//                 else if (left_min < right_min)
//                 {
//                     sum += left_min;
//                     fishspot[left] = index + 1;
//                 }
//                 else if (right_min < left_min)
//                 {
//                     sum += right_min;
//                     fishspot[right] = index + 1;
//                 }
//             }
//         }

//         left_min = right_min = 99999;

//         // Allot spot to last fishermen
//         while ((left > 0) && (fishspot[left] > 0))
//             left--;

//         if ((left > 0) && (fishspot[left] == 0))
//             left_min = gate[index] - left + 1;

//         while ((right <= N) && (fishspot[right] > 0))
//             right++;

//         if ((right <= N) && (fishspot[right] == 0))
//             right_min = right - gate[index] + 1;

//         if ((sum + left_min) == (sum + right_min))
//         {
//             npos = 2;
//             *pos1 = left;
//             *pos2 = right;
//             *score = sum + left_min;
//         }
//         else if ((sum + left_min) > (sum + right_min))
//         {
//             npos = 1;
//             *score = sum + right_min;
//             fishspot[right] = index + 1;
//         }
//         else if ((sum + left_min) < (sum + right_min))
//         {
//             npos = 1;
//             *score = sum + left_min;
//             fishspot[left] = index + 1;
//         }
//         return npos;
//     }

//     // Solve is used to select next gate
//     // and generate all combinations.
//     void solve(int index, int sum, int count)
//     {
//         int npos, pos1, pos2, score, i;

//         visited[index] = 1;

//         if (sum > Answer)
//             return;

//         npos = calculate_distance(index, &pos1, &pos2, &score);
//         sum += score;

//         if (count == MAX)
//         {
//             if (Answer > sum)
//                 Answer = sum;

//             return;
//         }

//         if (npos == 1)
//         {
//             for (i = 0; i < MAX; i++)
//             {
//                 if (visited[i] == 0)
//                 {
//                     solve(i, sum, count + 1);
//                     visited[i] = 0;
//                     reset_fishspot(i);
//                 }
//             }
//         }

//         else if (npos == 2)
//         {
//             fishspot[pos1] = index + 1;
//             for (i = 0; i < MAX; i++)
//             {
//                 if (visited[i] == 0)
//                 {
//                     solve(i, sum, count + 1);
//                     visited[i] = 0;
//                     reset_fishspot(i);
//                 }
//             }

//             fishspot[pos1] = 0;
//             fishspot[pos2] = index + 1;
//             for (i = 0; i < MAX; i++)
//             {
//                 if (visited[i] == 0)
//                 {
//                     solve(i, sum, count + 1);
//                     visited[i] = 0;
//                     reset_fishspot(i);
//                 }
//             }
//             fishspot[pos2] = 0;
//         }
//     }
// };

// // Driver Code
// int main()
// {
//     GFG g;

//     int i;

//     N = 10; // total no of fishing spots

//     // position of gates(1-based indexing)
//     gate[0] = 8;
//     gate[1] = 9;
//     gate[2] = 10;

//     // no of fishermen at each gate
//     fishermen[0] = 5; // gate1
//     fishermen[1] = 1; // gate 2
//     fishermen[2] = 2; // gate 3

//     for (i = 1; i <= N; i++)
//         fishspot[i] = 0;

//     Answer = 999999;

//     for (i = 0; i < MAX; i++)
//     {
//         g.solve(i, 0, 1);
//         visited[i] = 0;
//         g.reset_fishspot(i);
//     }

//     cout << Answer << endl;

//     return 0;
// }

// ##################################################################################################################################

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
int findR(vector<int> &vis, int cur, int n)
{
    for (int i = cur; i <= n; i++)
    {
        if (!vis[i])
            return i;
    }
    return 1e9;
}
int findL(vector<int> &vis, int cur, int n)
{
    for (int i = cur; i >= 1; i--)
    {
        if (!vis[i])
            return i;
    }
    return 1e9;
}
void solve(int a, int b, int c, int &ans, int dis, int cur, vector<int> &vis, vector<int> &gate, vector<int> &men, int n)
{
    if (dis > ans)
        return;
    if (men[cur] == 0)
    {
        if (cur == a)
            cur = b;
        else if (cur == b)
            cur = c;
        else
        {
            ans = min(ans, dis);
            return;
        }
    }
    int l = findL(vis, gate[cur], n), r = findR(vis, gate[cur], n);
    int disL = abs(gate[cur] - l) + 1, disR = abs(r - gate[cur]) + 1;
    bool goLeft = true, goRight = true;

    if (disL > disR)
        goLeft = false;
    if (disR > disL)
        goRight = false;

    if (goLeft)
    {
        vis[l] = 1;
        men[cur]--;
        solve(a, b, c, ans, dis + disL, cur, vis, gate, men, n);
        vis[l] = 0;
        men[cur]++;
    }
    if (goRight)
    {
        vis[r] = 1;
        men[cur]--;
        solve(a, b, c, ans, dis + disR, cur, vis, gate, men, n);
        vis[r] = 0;
        men[cur]++;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> gate(4), men(4);
        for (int i = 1; i <= 3; i++)
        {
            cin >> gate[i];
            cin >> men[i];
        }
        int ans = 1e9;
        vector<int> vis(n + 1, 0);
        solve(1, 2, 3, ans, 0, 1, vis, gate, men, n);
        solve(1, 3, 2, ans, 0, 1, vis, gate, men, n);
        solve(2, 1, 3, ans, 0, 2, vis, gate, men, n);
        solve(2, 3, 1, ans, 0, 2, vis, gate, men, n);
        solve(3, 2, 1, ans, 0, 3, vis, gate, men, n);
        solve(3, 1, 2, ans, 0, 3, vis, gate, men, n);
        cout << ans << endl;
    }

    return 0;
}