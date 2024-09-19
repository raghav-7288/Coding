/*
->In this approach, we create a Z array as part of the process.
->What is Z Array?
For a string str[0..n-1], Z array is of same length as string. An element Z[i] of Z array stores length of the longest substring
starting from str[i] which is also a prefix of str[0..n-1]. The first entry of Z array is meaning less as complete string is always
prefix of itself.
->How is Z array helpful in Searching Pattern in Linear time?
    The idea is to concatenate pattern and text, and create a string “P$T” where P is pattern,
    $ is a special character should not be present in pattern and text, and T is text.
    Build the Z array for concatenated string. In Z array, if Z value at any point is equal to pattern length,
    then pattern is present at that point.
Example:
    Pattern P = "aab",  Text T = "baabaa"
    The concatenated string is = "aab$baabaa"
    Z array for above concatenated string is {x, 1, 0, 0, 0, 3, 1, 0, 2, 1}.
    Since length of pattern is 3, the value 3 in Z array
    indicates presence of pattern.

                                    void zSearch(string text, string pat, vector<int>& matches){
                                        string concat=pat+'&'+text;
                                        int n=concat.length();
                                        vector<int> Z(n);
                                        for(int i=1;i<n;i++){
                                            int j=0,k=i;
                                            while(k<n){
                                                if(concat[j]==concat[k]){
                                                    j++;k++;
                                                }else break;
                                            }
                                            Z[i]=k-i;
                                        }
                                        for(int i=1;i<n;i++){
                                            if(Z[i]==pat.length()) matches.push_back(i-pat.length()-1);
                                        }
                                    }

*/
#include <bits/stdc++.h>
using namespace std;

// Function to search for pattern in text using Z algorithm
void ZSearch(string text, string pattern, vector<int> &matches)
{
    // Create concatenated string "P$T"
    string concat = pattern + "$" + text;
    int l = concat.length();

    vector<int> Z(l);
    for (int i = 1; i < l; i++)
    {
        int j = 0, k = i;
        while (k < l)
        {
            if (concat[j] == concat[k])
            {
                j++;
                k++;
            }
            else
                break;
        }
        Z[i] = k - i;
    }

    // Loop through Z array to find matches
    for (int i = 0; i < l; i++)
    {
        // If Z[i] is equal to length of pattern, we found a match
        if (Z[i] == pattern.length())
        {
            matches.push_back(i - pattern.length() - 1);
        }
    }
}

int main()
{
    string text = "abcaldfbabcaldkjhaabcaldabc";
    string pattern = "abc";

    vector<int> matches;
    ZSearch(text, pattern, matches);

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
