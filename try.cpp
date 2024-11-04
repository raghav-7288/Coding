/*
A directed graph has a Eulerian cycle if the following conditions are true
(1) All vertices with nonzero degrees belong to a single strongly connected component.
(2) In degree and out-degree of every vertex is the same. The algorithm assumes that the given graph has a Eulerian Circuit.
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> printCircuit(vector<vector<int>> &adj)
{
    vector<int> circuit;
    stack<int> st;
    st.push(0);
    while (!st.empty())
    {
        int node = st.top();
        if (!adj[node].empty())
        {
            int next = adj[node].back();
            adj[node].pop_back();
            st.push(next);
        }
        else
        {
            circuit.push_back(node);
            st.pop();
        }
    }
    reverse(circuit.begin(), circuit.end());
    return circuit;
}
int main()
{
    vector<vector<int>> adj1, adj2;
    adj1.resize(3);
    adj1[0].push_back(1);
    adj1[1].push_back(2);
    adj1[2].push_back(0);
    for (auto v : printCircuit(adj1))
    {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}