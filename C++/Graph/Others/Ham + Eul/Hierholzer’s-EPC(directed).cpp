/*
A directed graph has a Eulerian cycle if the following conditions are true
(1) All vertices with nonzero degrees belong to a single strongly connected component.
(2) In degree and out-degree of every vertex is the same. The algorithm assumes that the given graph has a Eulerian Circuit.
*/

//---------------------------------------------------Directed------------------------------------------------------------
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
    adj2.resize(7);
    adj2[0].push_back(1);
    adj2[0].push_back(6);
    adj2[1].push_back(2);
    adj2[2].push_back(0);
    adj2[2].push_back(3);
    adj2[3].push_back(4);
    adj2[4].push_back(2);
    adj2[4].push_back(5);
    adj2[5].push_back(0);
    adj2[6].push_back(4);
    for (auto v : printCircuit(adj2))
    {
        cout << v << " ";
    }
    return 0;
}

/*
---------------------------------------------------Undirected------------------------------------------------------------
stack<int> st;
    st.push(1);
    vector<int> circuit, used(m + 1);

    while (!st.empty())
    {
        int cur = st.top();
        if (deg[cur])
        {
            int next = adj[cur].back().first;
            int edge = adj[cur].back().second;
            adj[cur].pop_back();
            if (!used[edge])
            {
                deg[cur]--;
                deg[next]--;
                used[edge] = 1;
                st.push(next);
            }
        }
        else
        {
            circuit.push_back(cur);
            st.pop();
        }
    }

    if ((int)circuit.size() != m + 1)
        printf("IMPOSSIBLE\n");
    else
    {
        for (int v : circuit)
            cout << v << " ";
    }
*/