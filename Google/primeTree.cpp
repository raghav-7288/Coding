#include <bits/stdc++.h>
using namespace std;
class PrimeTree
{
public:
    void Sieve(int n, vector<int> &primes)
    {
        vector<bool> prime(n + 1, true);
        int p, i;
        for (p = 2; p * p <= n; p++)
        {
            if (!prime[p])
                continue;
            for (i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
        for (i = 2; i <= n; i++)
        {
            if (prime[i])
            {
                primes.push_back(i);
            }
        }
        return;
    }

    bool isPrime(int n, vector<int> &prime)
    {
        auto it = find(prime.begin(), prime.end(), n);
        return it != prime.end();
    }

    void dfs(int s, int p, int mod, vector<vector<int>> &adj, vector<vector<long long>> &dp, vector<int> &prime)
    {
        int i, j;
        for (i = 0; i < 25; i++)
        {
            dp[s][i] = 1;
        }
        for (auto u : adj[s])
        {
            if (u != p)
            {
                dfs(u, s, mod, adj, dp, prime);
                for (i = 0; i < 25; i++)
                {
                    long long pos = 0;
                    for (j = 0; j < 25; j++)
                    {
                        if (!isPrime(prime[i] + prime[j], prime))
                        {
                            pos = (pos + dp[u][j]) % mod;
                        }
                    }
                    dp[s][i] = (dp[s][i] * pos) % mod;
                }
            }
        }
        return;
    }

    int getNumberOfArrangements(int n, vector<vector<int>> &e, int maxInt = 200)
    {
        int i, j, mod = 1000000007;
        vector<int> primes;
        Sieve(maxInt, primes);
        vector<vector<long long>> dp(n + 1, vector<long long>(25, 0));
        vector<vector<int>> adj(n, vector<int>());
        for (i = 0; i < n - 1; i++)
        {
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
        }
        dfs(0, -1, mod, adj, dp, primes);
        int ans = 0;
        for (i = 0; i < 25; i++)
        {
            ans = (ans + dp[0][i]) % mod;
        }
        return ans;
    }
};
