//https://www.codingninjas.com/studio/problems/prim-s-mst_8230809?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 

using namespace std;

 

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)

{

    // Write your code here.

    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < g.size(); i++)

    {

        int u = g[i].first.first;

        int v = g[i].first.second;

        int w = g[i].second;

 

        adj[u].push_back(make_pair(v, w));

        adj[v].push_back(make_pair(u, w));

    }

    vector<int> key(n + 1);

    vector<bool> mst(n + 1);

    vector<int> parent(n + 1);

 

    for (int i = 0; i <= n; i++)

    {

        key[i] = INT_MAX;

        mst[i] = false;

        parent[i] = -1;

    }

    // let's start the algorithm

    key[1] = 0;

    parent[1] = -1;

 

    // Define a priority queue (min-heap) to get the minimum key value vertex

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push(make_pair(0, 1));

 

    while (!pq.empty())

    {

        int u = pq.top().second;  // Extract the vertex with minimum key value

        pq.pop();

 

        if (mst[u])

            continue;

 

        mst[u] = true;

 

        for (auto it : adj[u])

        {

            int v = it.first;

            int w = it.second;

            if (!mst[v] && w < key[v])

            {

                parent[v] = u;

                key[v] = w;

                pq.push(make_pair(key[v], v));

            }

        }

    }

 

    vector<pair<pair<int, int>, int>> result;

    for (int i = 2; i <= n; i++)

    {

        result.push_back({{parent[i], i}, key[i]});

    }

    return result;

}

