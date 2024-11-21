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
                                            Z[i]=k-i;      ->>>> gives TLE
                                        }
                                        for(int i=1;i<n;i++){
                                            if(Z[i]==pat.length()) matches.push_back(i-pat.length()-1);
                                        }
                                    }



*/

/*
Optimal for calculating Z array

        vector<int> get_z(string s)
        {
            int N = s.length();
            vector<int> Z(N, 0);
            int left = 0, right = 0;
            for (int i = 1; i < N; ++i)
            {
                if(i>right){
                    left=right=i;
                    while ((s[Z[i]] == s[i + Z[i]])) Z[i]++;
                    right = i + Z[i] - 1;
                }else{
                    if(i+Z[i-left] <= right) Z[i]=Z[i-left];
                    else{
                        left=i;
                        Z[i] = right-i+1;
                        while ((i + Z[i] < N) and (s[Z[i]] == s[i + Z[i]])) Z[i]++;
                        right = i + Z[i] - 1;
                    }
                }
            }
            return Z;
        }
        vector<int> search(string pat, string txt)
        {
            int n=pat.length();
            string concat = pat+"&"+txt;
            vector<int> z=get_z(concat), matches;
            for(int i=n+1;i<concat.length();i++){
                if(z[i]==n) matches.push_back(i-n);
            }
            return matches;
        }

*/