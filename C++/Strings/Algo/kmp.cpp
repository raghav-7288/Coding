/*
KMP (Knuth Morris Pratt) Pattern Searching:
->The basic idea behind KMP’s algorithm is: whenever we detect a mismatch (after some matches), we already know some of
the characters in the text of the next window. We take advantage of this information to avoid matching the characters that
we know will anyway match.
->we pre-process pattern and prepare an integer array lps[] that tells us the count of characters to be skipped
->For each sub-pattern pat[0..i] where i = 0 to m-1, lps[i] stores the length of the maximum matching proper prefix which is
also a suffix of the sub-pattern pat[0..i].
                lps[i] = the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i].
Note: lps[i] could also be defined as the longest prefix which is also a proper suffix. We need to use it properly in one
place to make sure that the whole substring is not considered.

->How to use lps[] to decide the next positions (or to know the number of characters to be skipped)?
1.We start the comparison of pat[j] with j = 0 with characters of the current window of text.
2.We keep matching characters txt[i] and pat[j] and keep incrementing i and j while pat[j] and txt[i] keep matching.
3.When we see a mismatch
    1.We know that characters pat[0..j-1] match with txt[i-j…i-1] (Note that j starts with 0 and increments it only when there is a match).
    2.We also know (from the above definition) that lps[j-1] is the count of characters of pat[0…j-1] that are both proper prefix and suffix.
    3.From the above two points, we can conclude that we do not need to match these lps[j-1] characters with txt[i-j…i-1] because we know that
    these characters will anyway match.

                            vector<int> kmp(string text, string pat){
                                int n=text.length(), m=pat.length();
                                vector<int> lps(m);
                                int i=1,len=0;
                                while(i<m){
                                    if(pat[i]==pat[len]){
                                        lps[i++]=++len;
                                    }else{
                                        if(len) len=lps[len-1];
                                        else lps[i++]=0;
                                    }
                                }
                                int j=0;i=0;
                                vector<int>& matches;
                                while(i<n){
                                    if(text[i]==pat[j]){
                                        i++;j++;
                                    }
                                    if(j==m){
                                        matches.push_back(i-j);
                                        j=lps[j-1];
                                    }else if(i<n && pat[j]!=text[i]){
                                        if(j) j=lps[j-1];
                                        else i++;
                                    }
                                }
                            }
*/
/*
    vector<int> get_lps(string pat){
        int n=pat.length();
        vector<int> lps(n);
        int i=1,j=0;
        while(i<n){
            if(pat[i]==pat[j]){
                lps[i]=j+1;
                j++;
            }else{
                while(j>0 && pat[j]!=pat[i]){
                    j=lps[j-1];
                }
                if(pat[j]==pat[i]){ 
                    lps[i]=j+1;
                    j++;
                }
            }
            i++;
        }
        return lps;
    }

*/

#include <bits/stdc++.h>
using namespace std;

// KMP pattern searching algorithm
void KMPSearch(const string &text, const string &pattern, vector<int> &matches)
{
    int N = text.length();
    int M = pattern.length();
    vector<int> lps(M);

    int i = 1, len = 0;

    while (i < M)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        { // (pattern[i] != pattern[len])
            if (len != 0)
            {
                len = lps[len - 1];
                // Note that we do not increment i here
            }
            else
            { // if (len == 0)
                lps[i] = 0;
                i++;
            }
        }
    }

    int j = 0;
    i = 0;

    while (i < N)
    {
        if (pattern[j] == text[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            matches.push_back(i - j);
            j = lps[j - 1];
        }
        // Mismatch after j matches
        else if (i < N && pattern[j] != text[i])
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

int main()
{
    string text = "geeksforgeeks";
    string pattern = "geek";

    vector<int> matches;

    KMPSearch(text, pattern, matches);

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
