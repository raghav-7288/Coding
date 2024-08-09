#include <bits/stdc++.h>
using namespace std;
// area=max(area,(leftSmall - rightSmall) * height) => for all i;
int area(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    int left_small[n], right_small[n];
    // LeftSmall
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (st.empty())
            left_small[i] = 0;
        else
        {
            left_small[i] = st.top() + 1;
        }
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    // RightSmall
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (st.empty())
            right_small[i] = n - 1;
        else
        {
            right_small[i] = st.top() - 1;
        }
        st.push(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, (right_small[i] - left_small[i] + 1) * heights[i]);
    }
    return ans;
}
// optimised
int area2(vector<int> histo)
{
    stack<int> st;
    int maxA = 0;
    int n = histo.size();
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i]))
        {
            int height = histo[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            maxA = max(maxA, width * height);
        }
        st.push(i);
    }
    return maxA;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    vector<int> a = {2, 1, 5, 6, 2, 3};
    cout << area(a);
    return 0;
}