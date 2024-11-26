#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<string> attributesSet(int numberOfAttributes, double supportThreshold)
{
    // Read the data from census.csv
    ifstream file("census.csv");
    if (!file.is_open())
    {
        cerr << "Error opening file" << endl;
        return {};
    }

    vector<unordered_set<int>> transactions;
    unordered_map<string, int> attrValueToId;
    vector<string> idToAttrValue;
    int attrValueId = 0;

    string line;
    int recordId = 0;
    while (getline(file, line))
    {
        // Each line contains 72 comma-separated values in the form attribute=value
        unordered_set<int> transaction;
        stringstream ss(line);
        string token;
        while (getline(ss, token, ','))
        {
            // Remove any leading/trailing whitespace
            token.erase(token.find_last_not_of(" \n\r\t") + 1);
            token.erase(0, token.find_first_not_of(" \n\r\t"));

            if (attrValueToId.find(token) == attrValueToId.end())
            {
                attrValueToId[token] = attrValueId;
                idToAttrValue.push_back(token);
                attrValueId++;
            }
            transaction.insert(attrValueToId[token]);
        }
        transactions.push_back(transaction);
        recordId++;
    }
    file.close();

    int totalRecords = transactions.size();
    int minSupportCount = (int)(supportThreshold * totalRecords + 1e-6); // Adding small epsilon to handle floating point precision

    // Frequent itemsets
    vector<map<set<int>, int>> frequentItemsets;
    frequentItemsets.resize(numberOfAttributes + 1);

    // Generate frequent 1-itemsets
    unordered_map<int, int> itemCounts;
    for (int i = 0; i < transactions.size(); i++)
    {
        for (int item : transactions[i])
        {
            itemCounts[item]++;
        }
    }

    for (auto &itemCount : itemCounts)
    {
        if (itemCount.second >= minSupportCount)
        {
            set<int> itemset = {itemCount.first};
            frequentItemsets[1][itemset] = itemCount.second;
        }
    }

    // Generate frequent k-itemsets
    for (int k = 2; k <= numberOfAttributes; k++)
    {
        if (frequentItemsets[k - 1].empty())
        {
            break;
        }
        map<set<int>, int> candidateItemsets;

        // Generate candidate itemsets
        auto prevItemsets = frequentItemsets[k - 1];
        vector<set<int>> prevItemsetList;
        for (auto &itemsetCount : prevItemsets)
        {
            prevItemsetList.push_back(itemsetCount.first);
        }

        int prevItemsetSize = prevItemsetList.size();
        for (int i = 0; i < prevItemsetSize; i++)
        {
            for (int j = i + 1; j < prevItemsetSize; j++)
            {
                // Join step
                set<int> itemset1 = prevItemsetList[i];
                set<int> itemset2 = prevItemsetList[j];

                vector<int> v1(itemset1.begin(), itemset1.end());
                vector<int> v2(itemset2.begin(), itemset2.end());

                bool canJoin = true;
                for (int m = 0; m < k - 2; m++)
                {
                    if (v1[m] != v2[m])
                    {
                        canJoin = false;
                        break;
                    }
                }

                if (canJoin)
                {
                    set<int> candidateItemset = itemset1;
                    candidateItemset.insert(v2[k - 2]);

                    // Prune step: all subsets must be frequent
                    bool allSubsetsFrequent = true;
                    for (int item : candidateItemset)
                    {
                        set<int> subset = candidateItemset;
                        subset.erase(item);
                        if (frequentItemsets[k - 1].find(subset) == frequentItemsets[k - 1].end())
                        {
                            allSubsetsFrequent = false;
                            break;
                        }
                    }
                    if (allSubsetsFrequent)
                    {
                        candidateItemsets[candidateItemset] = 0;
                    }
                }
            }
        }

        // Count supports
        for (auto &candidate : candidateItemsets)
        {
            int count = 0;
            for (auto &transaction : transactions)
            {
                bool containsAll = true;
                for (int item : candidate.first)
                {
                    if (transaction.find(item) == transaction.end())
                    {
                        containsAll = false;
                        break;
                    }
                }
                if (containsAll)
                {
                    count++;
                }
            }
            if (count >= minSupportCount)
            {
                frequentItemsets[k][candidate.first] = count;
            }
        }
    }

    // Collect the frequent itemsets of size numberOfAttributes
    vector<string> result;
    for (auto &itemsetCount : frequentItemsets[numberOfAttributes])
    {
        set<int> itemset = itemsetCount.first;
        vector<string> attrValues;
        for (int id : itemset)
        {
            attrValues.push_back(idToAttrValue[id]);
        }
        sort(attrValues.begin(), attrValues.end());
        string itemsetStr = "";
        for (int i = 0; i < attrValues.size(); i++)
        {
            if (i > 0)
                itemsetStr += ",";
            itemsetStr += attrValues[i];
        }
        result.push_back(itemsetStr);
    }

    sort(result.begin(), result.end());

    return result;
}

int main()
{
    int numberOfAttributes;
    double supportThreshold;
    cin >> numberOfAttributes >> supportThreshold;

    vector<string> result = attributesSet(numberOfAttributes, supportThreshold);

    for (auto &s : result)
    {
        cout << s << endl;
    }

    return 0;
}
