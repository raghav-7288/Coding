#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll mod = 1e9 + 7;

// Function to compute (a^b) % mod using binary exponentiation
ll power(ll a, ll b)
{
    ll res = 1;
    a %= mod; // Ensure 'a' is within mod to prevent overflow
    while (b)
    {
        if (b & 1)                 // If current bit is set
            res = (res * a) % mod; // Multiply result with 'a' and take modulo
        a = (a * a) % mod;         // Square 'a' and take modulo
        b /= 2;                    // Move to the next bit
    }
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    // For local testing: Redirect input and output
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    ll n;
    cin >> n; // Number of distinct prime factors

    vector<ll> x(n), k(n); // Vectors to store prime factors and their exponents
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> k[i]; // Input prime factor and its exponent
    }

    ll numOfDiv = 1;         // Initialize number of divisors
    ll sumOfDiv = 1;         // Initialize sum of divisors
    ll productOfDivisor = 1; // Initialize product of divisors
    ll mod = 1e9 + 7;        // Modulo value

    // Calculate the number of divisors
    // Formula: numOfDiv = Π (k[i] + 1)
    for (auto p : k)
    {
        numOfDiv = (numOfDiv * ((p + 1) % mod)) % mod; // Multiply and take modulo
    }

    // Calculate the sum of divisors
    // Formula: sumOfDiv = Π [ (x[i]^(k[i]+1) - 1) / (x[i] - 1) ]
    for (int i = 0; i < n; i++)
    {
        // Compute numerator: x[i]^(k[i]+1) - 1
        ll temp = (power(x[i], k[i] + 1) - 1 + mod) % mod; // Add 'mod' to handle negative result

        // Compute denominator's modular inverse: (x[i] - 1)^(mod - 2)
        ll denom_inv = power(x[i] - 1, mod - 2); // Fermat's little theorem for modular inverse

        // Multiply temp with the modular inverse of the denominator
        temp = (temp * denom_inv) % mod;

        // Update the sum of divisors
        sumOfDiv = (sumOfDiv * temp) % mod;
    }

    // Calculate the product of divisors
    // Formula: productOfDivisors = N^(numOfDiv / 2)
    ll num_divi = 1; // Exponent for N in the product of divisors
    ll flag = 0;     // Flag to check if an odd exponent is found

    // Calculate the exponent num_divi considering the properties of exponents
    for (int i = 0; i < n; i++)
    {
        if (k[i] % 2 == 1 && flag == 0)
        {
            // If the exponent k[i] is odd and no previous odd exponent is found
            num_divi *= ((k[i] + 1) / 2); // Multiply with (k[i]+1)/2
            num_divi %= (mod - 1);        // Take modulo (mod - 1) due to Fermat's theorem
            flag = 1;                     // Set flag to indicate an odd exponent has been handled
        }
        else
        {
            // Multiply with (k[i]+1)
            num_divi *= (k[i] + 1) % (mod - 1);
            num_divi %= (mod - 1);
        }
    }

    // If no odd exponents were found, divide all exponents by 2
    if (flag == 0)
    {
        for (int i = 0; i < n; i++)
        {
            k[i] /= 2;
        }
    }

    ll number = 1; // The base number N for the final exponentiation
    for (int i = 0; i < n; i++)
    {
        // Reconstruct N with adjusted exponents
        number = (number * power(x[i], k[i])) % mod;
    }

    // Compute the final product of divisors
    productOfDivisor = power(number, num_divi); // (N')^num_divi mod mod

    // Output the results
    cout << numOfDiv << " " << sumOfDiv << " " << productOfDivisor;
    return 0;
}
