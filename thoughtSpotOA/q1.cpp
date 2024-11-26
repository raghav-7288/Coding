#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;              // Modulo value for all computations
const int MAX = 2005;                 // Maximum size for factorial and inverse factorial arrays
vector<long long> factorial(MAX);     // Array to store factorials
vector<long long> inv_factorial(MAX); // Array to store inverse factorials

// Function to compute a^b % MOD using fast exponentiation (modular exponentiation)
long long modpow(long long a, long long b)
{
    long long res = 1;
    a %= MOD; // Ensure a is within the modulo range
    while (b)
    {
        if (b % 2) // If b is odd, multiply the result by a
            res = res * a % MOD;
        a = a * a % MOD; // Square a for the next bit of b
        b /= 2;          // Halve b
    }
    return res;
}

// Initialize factorial and inverse factorial arrays up to n
void init_factorials(int n)
{
    factorial[0] = inv_factorial[0] = 1;
    // Compute factorials modulo MOD
    for (int i = 1; i <= n; ++i)
        factorial[i] = factorial[i - 1] * i % MOD;

    // Compute the inverse of factorial[n] using Fermat's Little Theorem
    inv_factorial[n] = modpow(factorial[n], MOD - 2);

    // Compute the inverse factorials for all numbers <= n
    for (int i = n - 1; i >= 1; --i)
        inv_factorial[i] = inv_factorial[i + 1] * (i + 1) % MOD;
}

// Function to calculate C(n, r) % MOD (binomial coefficient modulo MOD)
long long comb(int n, int r)
{
    if (r < 0 || r > n)
        return 0; // If r is out of range, return 0
    return factorial[n] * inv_factorial[r] % MOD * inv_factorial[n - r] % MOD;
}

// Main function to calculate the number of valid configurations
int getNumConfigurations(int n, vector<int> &time, int m, int maxTime)
{
    vector<int> zeroTimeFilters;     // Store indices of zero-time filters
    vector<int> positiveTimeFilters; // Store indices of positive-time filters
    vector<int> positiveTime;        // Store the time values of positive-time filters

    // Separate filters into zero-time and positive-time filters
    for (int i = 0; i < n; ++i)
    {
        if (time[i] == 0)
        {
            zeroTimeFilters.push_back(i); // Zero-time filter
        }
        else
        {
            positiveTimeFilters.push_back(i); // Positive-time filter
            positiveTime.push_back(time[i]);  // Store positive time values
        }
    }

    int n0 = zeroTimeFilters.size();     // Number of zero-time filters
    int n1 = positiveTimeFilters.size(); // Number of positive-time filters

    // Initialize factorials for combinations up to m + n0
    init_factorials(m + n0);

    // Precompute combinations for zero-time filters
    vector<int> combZero(m + 1, 0); // combZero[z] = number of ways to assign z images to zero-time filters
    if (n0 > 0)
    {
        for (int z = 0; z <= m; ++z)
        {
            // Number of ways to assign z images to n0 zero-time filters: C(z + n0 - 1, n0 - 1)
            combZero[z] = comb(z + n0 - 1, n0 - 1);
        }
    }
    else
    {
        combZero[0] = 1; // If no zero-time filters, there's only one way (assigning 0 images)
    }

    // Dynamic programming for positive-time filters
    vector<vector<int>> dp(m + 1, vector<int>(maxTime + 1, 0)); // dp[images][timeUsed] = ways to assign 'images' filters using 'timeUsed' time
    dp[0][0] = 1;                                               // Base case: 1 way to assign 0 images with 0 time used

    // Iterate over each positive-time filter
    for (int idx = 0; idx < n1; ++idx)
    {
        int t = positiveTime[idx]; // Time required for this filter
        // Copy of dp to prevent overwriting in the same iteration
        vector<vector<int>> new_dp = dp;
        // Try all possible image counts and time usage
        for (int images = 0; images <= m; ++images)
        {
            for (int timeUsed = 0; timeUsed <= maxTime; ++timeUsed)
            {
                if (dp[images][timeUsed]) // If there are ways to assign 'images' filters using 'timeUsed' time
                {
                    // Try assigning 'k' filters, where each filter takes 't' time
                    for (int k = 1; images + k <= m && timeUsed + k * t <= maxTime; ++k)
                    {
                        new_dp[images + k][timeUsed + k * t] = (new_dp[images + k][timeUsed + k * t] + dp[images][timeUsed]) % MOD;
                    }
                }
            }
        }
        dp = new_dp; // Update dp for the next iteration
    }

    // Combine results from zero-time and positive-time filters
    int result = 0;
    for (int z = 0; z <= m; ++z)
    {
        int imagesPositive = m - z; // Number of positive-time filters to assign
        int totalWays = 0;
        // Sum over all possible time usages for the positive-time filters
        for (int totalTime = 0; totalTime <= maxTime; ++totalTime)
        {
            totalWays = (totalWays + dp[imagesPositive][totalTime]) % MOD;
        }
        int waysZero = combZero[z];                                 // Number of ways to assign z images to zero-time filters
        result = (result + 1LL * waysZero * totalWays % MOD) % MOD; // Combine the results from zero-time and positive-time filters
    }

    return result; // Return the final result
}

int main()
{
    // Sample input
    vector<int> time = {1, 1, 1}; // Time required for each filter
    int m = 3;                    // Total number of images to assign
    int maxTime = 3;              // Maximum total time allowed for assignment

    cout << getNumConfigurations(time.size(), time, m, maxTime) << endl; // Output the result
    return 0;
}
