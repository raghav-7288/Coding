#include <bits/stdc++.h>
using namespace std;
/*
Everything case insensitive
3.'&' and ',' considered as spaces
4. multiple spaces is a single space
1.ignore leading a,an,the
2.ignore trailing {inc. , corp , llc , l.l.c. , llc.}
5.ignore and if it is in between
*/
void transform(string &str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    regex leading_articles_pattern("^\\s*(a|an|the)\\s+");
    str = regex_replace(str, leading_articles_pattern, "");

    regex trailing_terms_pattern("\\s+(inc\\.|corp|llc\\.?|l\\.l\\.c\\.)\\s*$", regex_constants::icase);
    str = regex_replace(str, trailing_terms_pattern, "");

    regex middle_and_pattern("\\s+and\\s+", regex_constants::icase);
    str = regex_replace(str, middle_and_pattern, " ");

    replace(str.begin(), str.end(), '&', ' ');
    replace(str.begin(), str.end(), ',', ' ');

    regex space_pattern("\\s+");
    str = regex_replace(str, space_pattern, " ");
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    cin.ignore();
    vector<string> str(n);
    unordered_set<string> st;
    for (int i = 0; i < n; i++)
    {
        getline(cin, str[i]);
    }

    for (auto s : str)
    {
        int pos_name = s.find_first_of('|');
        // cout << pos_name;
        string id = s.substr(0, pos_name), name = s.substr(pos_name + 1);
        // cout << id << "," << name << endl;
        transform(name);
        // cout << name << endl;
        if (st.find(name) == st.end())
        {
            cout << id << '|' << "Name Available\n";
            st.insert(name);
        }
        else
        {
            cout << id << '|' << "Name Not Available\n";
        }
    }

    // for (auto s : str)
    //     cout << s << endl;
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

string preprocess_name(string &str)
{
    // lower the string, ignore spaces;
    vector<string> temp;
    for (auto &x : str)
    {
        if (x >= 'A' && x <= 'Z')
            x = x + 32;
        if (x == '&' || x == ',')
            x = ' ';
    }
    string t;
    stringstream s(str);
    int index = 0;
    while (getline(s, t, ' '))
    {
        temp.push_back(t);
    }
    if (temp[0] == "a" || temp[0] == "the" || temp[0] == "an")
        index++;

    int last = temp.size() - 1;
    if (temp[last] == "inc." || temp[last] == "corp" || temp[last] == "llc" || temp[last] == "llc." || temp[last] == "l.l.c.")
        last--;

    string name = "";
    for (int i = index; i <= last; i++)
    {
        if (temp[i] != "and" || (index == 0))
            name = name + temp[i] + " ";
    }
    temp.pop_back();
    return name;
}

void solve(vector<string> &arr, int n)
{
    map<string, bool> mp;
    string temp;
    for (auto str : arr)
    {
        string id = "";
        char ch = str[0];
        int index = 0;
        while (str[index] != '|')
            index++;
        id = str.substr(0, index);
        string name = str.substr(index + 1);
        name = preprocess_name(name);
        bool avail = true;
        if (name == "")
            avail = false;
        else
        {
            int f = 0;
            for (auto x : name)
            {
                if (x != ' ')
                    f = 1;
            }
            if (f == 0)
                avail = false;
            if (avail && mp.find(name) == mp.end())
            {
                mp[name] = true;
                avail = true;
            }
            else
                avail = false;
        }
        if (avail)
            cout << id << "|" << "Name Available\n";
        else
            cout << id << "|Name not Available\n";
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    cin.ignore();
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        string str;
        getline(cin, str);
        arr[i] = str;
    }

    solve(arr, n);
    return 0;
}
*/