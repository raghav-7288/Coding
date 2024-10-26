#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Constants for double hashing
const int MOD1 = 1000000007;
const int MOD2 = 1000000009;
const int BASE1 = 911382629;
const int BASE2 = 357142857;

// Maximum possible length of S
const int MAXN = 1000005;

// Power arrays for both hash functions
ll power1_MOD1[MAXN];
ll power2_MOD1[MAXN];
ll power1_MOD2[MAXN];
ll power2_MOD2[MAXN];

// Prefix hash arrays for S
ll prefixHash1_MOD1[MAXN];
ll prefixHash2_MOD1[MAXN];
ll prefixHash1_MOD2[MAXN];
ll prefixHash2_MOD2[MAXN];

// Prefix hash arrays for reversed S
ll prefixRevHash1_MOD1[MAXN];
ll prefixRevHash2_MOD1[MAXN];
ll prefixRevHash1_MOD2[MAXN];
ll prefixRevHash2_MOD2[MAXN];

// Global variables
int N, Q;
vector<vector<int>> adj;
char C[100005];
string S;
int startIdx[100005];
int endIdx[100005];

// Function to precompute powers
void precompute_powers(int max_len)
{
    power1_MOD1[0] = 1;
    power2_MOD1[0] = 1;
    power1_MOD2[0] = 1;
    power2_MOD2[0] = 1;
    for (int i = 1; i <= max_len; i++)
    {
        power1_MOD1[i] = (power1_MOD1[i - 1] * BASE1) % MOD1;
        power2_MOD1[i] = (power2_MOD1[i - 1] * BASE2) % MOD1;
        power1_MOD2[i] = (power1_MOD2[i - 1] * BASE1) % MOD2;
        power2_MOD2[i] = (power2_MOD2[i - 1] * BASE2) % MOD2;
    }
}

// Post-order traversal to build S and map start/end indices
void dfs(int u, int parent_node)
{
    // Traverse children in increasing order
    for (auto &v : adj[u])
    {
        if (v != parent_node)
        {
            dfs(v, u);
        }
    }
    // Record the start index before appending the character
    startIdx[u] = S.size();
    // Append the character
    S += C[u];
    // Record the end index
    endIdx[u] = S.size() - 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Read number of nodes
    cin >> N;

    adj.assign(N + 1, vector<int>());

    // Read edges
    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Read characters
    for (int i = 1; i <= N; i++)
    {
        cin >> C[i];
    }

    // Sort the children of each node in increasing order
    for (int u = 1; u <= N; u++)
    {
        sort(adj[u].begin(), adj[u].end());
    }

    // Perform post-order traversal to build S and map indices
    dfs(1, -1);

    // Reverse S to prepare for reverse hashing
    string S_rev = S;
    reverse(S_rev.begin(), S_rev.end());

    // Precompute powers
    precompute_powers(S.size());

    // Compute prefix hashes for S
    prefixHash1_MOD1[0] = S[0];
    prefixHash2_MOD1[0] = S[0];
    prefixHash1_MOD2[0] = S[0];
    prefixHash2_MOD2[0] = S[0];
    for (int i = 1; i < S.size(); i++)
    {
        prefixHash1_MOD1[i] = (prefixHash1_MOD1[i - 1] * BASE1 + S[i]) % MOD1;
        prefixHash2_MOD1[i] = (prefixHash2_MOD1[i - 1] * BASE2 + S[i]) % MOD1;
        prefixHash1_MOD2[i] = (prefixHash1_MOD2[i - 1] * BASE1 + S[i]) % MOD2;
        prefixHash2_MOD2[i] = (prefixHash2_MOD2[i - 1] * BASE2 + S[i]) % MOD2;
    }

    // Compute prefix hashes for S_rev
    prefixRevHash1_MOD1[0] = S_rev[0];
    prefixRevHash2_MOD1[0] = S_rev[0];
    prefixRevHash1_MOD2[0] = S_rev[0];
    prefixRevHash2_MOD2[0] = S_rev[0];
    for (int i = 1; i < S_rev.size(); i++)
    {
        prefixRevHash1_MOD1[i] = (prefixRevHash1_MOD1[i - 1] * BASE1 + S_rev[i]) % MOD1;
        prefixRevHash2_MOD1[i] = (prefixRevHash2_MOD1[i - 1] * BASE2 + S_rev[i]) % MOD1;
        prefixRevHash1_MOD2[i] = (prefixRevHash1_MOD2[i - 1] * BASE1 + S_rev[i]) % MOD2;
        prefixRevHash2_MOD2[i] = (prefixRevHash2_MOD2[i - 1] * BASE2 + S_rev[i]) % MOD2;
    }

    // Read number of queries
    cin >> Q;

    while (Q--)
    {
        int u;
        cin >> u;
        // Get start and end indices for S(u)
        int l = startIdx[u];
        int r = endIdx[u];
        int len = r - l + 1;

        // Compute hash for S(u) in forward direction
        // Hash1_MOD1
        ll hash1_forward_mod1 = prefixHash1_MOD1[r];
        if (l > 0)
        {
            hash1_forward_mod1 = (hash1_forward_mod1 - (prefixHash1_MOD1[l - 1] * power1_MOD1[len]) % MOD1 + MOD1) % MOD1;
        }
        // Hash2_MOD1
        ll hash2_forward_mod1 = prefixHash2_MOD1[r];
        if (l > 0)
        {
            hash2_forward_mod1 = (hash2_forward_mod1 - (prefixHash2_MOD1[l - 1] * power2_MOD1[len]) % MOD1 + MOD1) % MOD1;
        }
        // Hash1_MOD2
        ll hash1_forward_mod2 = prefixHash1_MOD2[r];
        if (l > 0)
        {
            hash1_forward_mod2 = (hash1_forward_mod2 - (prefixHash1_MOD2[l - 1] * power1_MOD2[len]) % MOD2 + MOD2) % MOD2;
        }
        // Hash2_MOD2
        ll hash2_forward_mod2 = prefixHash2_MOD2[r];
        if (l > 0)
        {
            hash2_forward_mod2 = (hash2_forward_mod2 - (prefixHash2_MOD2[l - 1] * power2_MOD2[len]) % MOD2 + MOD2) % MOD2;
        }

        // Compute hash for S(u) in reverse direction
        // Corresponding indices in S_rev
        // Position in S_rev for S[u] is: len(S) -1 - r to len(S) -1 - l
        int rev_l = S.size() - 1 - r;
        int rev_r = S.size() - 1 - l;

        // Hash1_MOD1 for reverse
        ll hash1_rev_mod1 = prefixRevHash1_MOD1[rev_r];
        if (rev_l > 0)
        {
            hash1_rev_mod1 = (hash1_rev_mod1 - (prefixRevHash1_MOD1[rev_l - 1] * power1_MOD1[len]) % MOD1 + MOD1) % MOD1;
        }
        // Hash2_MOD1 for reverse
        ll hash2_rev_mod1 = prefixRevHash2_MOD1[rev_r];
        if (rev_l > 0)
        {
            hash2_rev_mod1 = (hash2_rev_mod1 - (prefixRevHash2_MOD1[rev_l - 1] * power2_MOD1[len]) % MOD1 + MOD1) % MOD1;
        }
        // Hash1_MOD2 for reverse
        ll hash1_rev_mod2 = prefixRevHash1_MOD2[rev_r];
        if (rev_l > 0)
        {
            hash1_rev_mod2 = (hash1_rev_mod2 - (prefixRevHash1_MOD2[rev_l - 1] * power1_MOD2[len]) % MOD2 + MOD2) % MOD2;
        }
        // Hash2_MOD2 for reverse
        ll hash2_rev_mod2 = prefixRevHash2_MOD2[rev_r];
        if (rev_l > 0)
        {
            hash2_rev_mod2 = (hash2_rev_mod2 - (prefixRevHash2_MOD2[rev_l - 1] * power2_MOD2[len]) % MOD2 + MOD2) % MOD2;
        }

        // Compare forward and reverse hashes
        bool is_palindrome = false;
        if (hash1_forward_mod1 == hash1_rev_mod1 && hash2_forward_mod2 == hash2_rev_mod2)
        {
            is_palindrome = true;
        }

        cout << (is_palindrome ? "1" : "0") << "\n";
    }
}
