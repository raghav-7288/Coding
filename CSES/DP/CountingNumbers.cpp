#include <bits/stdc++.h>
using namespace std;

#define ll long long

// DP table to memoize results of subproblems
// Dimensions: [number of digits][previous digit + 1][leading zero flag][tight flag]
// We add 1 to the previous digit index to handle prev = -1
vector<vector<vector<vector<ll>>>> dp(
    20, vector<vector<vector<ll>>>(
            11, vector<vector<ll>>(
                    2, vector<ll>(
                           2, -1))));

// Recursive function implementing Digit DP
ll count_numbers(string &s, ll cur_pos, ll prev_digit, ll leading_zero, ll tight)
{
    // Base case: If all positions are processed, return 1 (valid number)
    if (cur_pos == 0)
        return 1;

    // Adjust prev_digit index to handle prev_digit = -1
    ll prev_index = prev_digit + 1;

    // Check if result is already computed
    if (dp[cur_pos][prev_index][leading_zero][tight] != -1)
        return dp[cur_pos][prev_index][leading_zero][tight];

    ll limit = 9; // Maximum digit we can use at this position

    // If tight is true, we cannot exceed the current digit in the bound
    if (tight)
    {
        limit = s[s.size() - cur_pos] - '0'; // Current digit in the bound
    }

    ll ans = 0; // Initialize answer for this state

    // Try all possible digits at this position
    for (ll d = 0; d <= limit; d++)
    {
        // If not leading zero and current digit equals previous digit, skip (constraint)
        if (!leading_zero && d == prev_digit)
            continue;

        // Update leading_zero flag
        ll new_leading_zero = (leading_zero && d == 0) ? 1 : 0;

        // Update tight flag
        ll new_tight = (tight && d == limit) ? 1 : 0;

        // Recursively call for the next position
        ans += count_numbers(s, cur_pos - 1, d, new_leading_zero, new_tight);
    }

    // Store result in DP table
    return dp[cur_pos][prev_index][leading_zero][tight] = ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    // Input range [a, b]
    ll a, b;
    cin >> a >> b;

    // Convert numbers to strings for easy digit access
    string str_a = to_string(a - 1); // For numbers less than 'a'
    string str_b = to_string(b);     // For numbers up to 'b'

    ll cnt1 = 0; // Count of valid numbers less than 'a'

    // Initialize DP table with -1 for fresh computation
    fill(dp.begin(), dp.end(), vector<vector<vector<ll>>>(11, vector<vector<ll>>(2, vector<ll>(2, -1))));

    // If 'a' is not zero, compute count of valid numbers less than 'a'
    if (a != 0)
        cnt1 = count_numbers(str_a, str_a.size(), -1, 1, 1);

    // Initialize DP table again for the new computation
    fill(dp.begin(), dp.end(), vector<vector<vector<ll>>>(11, vector<vector<ll>>(2, vector<ll>(2, -1))));

    // Compute count of valid numbers up to 'b'
    ll cnt2 = count_numbers(str_b, str_b.size(), -1, 1, 1);

    // Output the total count of valid numbers in the range [a, b]
    cout << cnt2 - cnt1;
    return 0;
}
