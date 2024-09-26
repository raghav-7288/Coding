/*
->Rabin Karp algorithm matches the hash value of the pattern with the hash value of the current substring of text,
and if the hash values match then only it starts matching individual characters.

->So Rabin Karp algorithm needs to calculate hash values for the following strings.
    Pattern itself
    All the substrings of the text of length m which is the size of pattern.

->The hash value is calculated using a rolling hash function, which allows you to update the hash value for a new substring
by efficiently removing the contribution of the old character and adding the contribution of the new character.
This makes it possible to slide the pattern over the text and calculate the hash value for each substring without
recalculating the entire hash from scratch.

->Iterate over each character in the pattern from left to right.
For each character ‘c’ at position ‘i’, calculate its contribution to the hash value as
‘c * (base^(pattern_length – i – 1)) % p’ and add it to ‘hash‘.
This gives you the hash value for the entire pattern.

->Update the hash value for each subsequent substring:
To slide the pattern one position to the right, you remove the contribution of the leftmost character and add the
contribution of the new character on the right.
The formula for updating the hash value when moving from position ‘i’ to ‘i+1’ is:
    hash = (hash - (text[i - pattern_length] * (base^(pattern_length - 1))) % prime) * base + text[i]

->Time Complexity:
The average and best-case running time of the Rabin-Karp algorithm is O(n+m), but its worst-case time is O(nm).
The worst case of the Rabin-Karp algorithm occurs when all characters of pattern and text are the
same as the hash values of all the substrings of T[] match with the hash value of P[].
->Auxiliary Space: O(1)

                                            vector<int> search(string pat, string txt)
                                                {
                                                    int n=pat.length(), m=txt.length();
                                                    int b=256, p=101;
                                                    long long curHash=0, patHash=0, power=1;
                                                    for(int i=1;i<n;i++) power = (power*b)%p;
                                                    for(int i=0;i<n;i++){
                                                        patHash = (patHash*b + pat[i])%p;
                                                        curHash = (curHash*b + txt[i])%p;
                                                    }
                                                    vector<int> matches;
                                                    for(int i=0;i<=m-n;i++){
                                                        if(curHash==patHash){
                                                            bool match=true;
                                                            for(int k=0;k<n;k++){
                                                                if(pat[k]!=txt[i+k]){
                                                                    match=false;
                                                                    break;
                                                                }
                                                            }
                                                            if(match) matches.push_back(i+1);
                                                        }
                                                        if(i<m-n){
                                                            curHash = (curHash-txt[i]*power)%p;
                                                            curHash = (curHash*b + txt[i+n])%p;
                                                            if(curHash<0) curHash+=p;
                                                        }
                                                    }
                                                    return matches;
                                                }
*/

#include <bits/stdc++.h>
using namespace std;

// Rabin-Karp algorithm
vector<int> rabinKarp(string text, string pattern, int b = 256, int p = 101)
{
    int n = text.size();
    int m = pattern.size();
    long long patternHash = 0, currentHash = 0;
    vector<int> result;
    long long highestPower = 1; // This will store b^(m-1) % p

    // Calculate b^(m-1) % p
    for (int i = 0; i < m - 1; i++)
    {
        highestPower = (highestPower * b) % p;
    }

    // Calculate the hash value for the pattern and first window of text
    for (int i = 0; i < m; i++)
    {
        patternHash = (patternHash * b + pattern[i]) % p;
        currentHash = (currentHash * b + text[i]) % p;
    }

    // Slide over the text
    for (int i = 0; i <= n - m; i++)
    {
        // If the current window hash matches the pattern hash, check character by character
        if (patternHash == currentHash)
        {
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                result.push_back(i);
            }
        }
        // Slide the pattern to the right (if possible)
        if (i < n - m)
        {
            currentHash = (currentHash - text[i] * highestPower) % p;
            currentHash = (currentHash * b + text[i + m]) % p;

            // Make sure currentHash is positive
            if (currentHash < 0)
            {
                currentHash += p;
            }
        }
    }

    return result;
}
int main()
{
    string text = "asdhgabcaldabcaldabc";
    string pattern = "abc";

    vector<int> matches = rabinKarp(text, pattern);

    if (matches.empty())
    {
        cout << "No match found!" << endl;
    }
    else
    {
        cout << "Pattern found at positions: ";
        for (int i : matches)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
