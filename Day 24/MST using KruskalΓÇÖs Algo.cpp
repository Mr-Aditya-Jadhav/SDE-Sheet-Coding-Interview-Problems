//https://www.codingninjas.com/studio/problems/kruskal-s-minimum-spanning-tree-algorithm_8230804?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 
static bool cmp(vector<int> &a, vector<int> &b){
	return a[2] < b[2];
}

int findParent(vector<int> &parent, int node){
	if(parent[node] == node){
		return node;
	}

	return parent[node] = findParent(parent, parent[node]);
}

void makeunion(vector<int> &parent, vector<int> &rank, int u, int v){
	u = findParent(parent,u);
	v = findParent(parent,v);

	if(rank[u] < rank[v]){
		parent[u] = v;
	}else if(rank[v] < rank[u]){
		parent[v] = u;
	}else{
		parent[v] = u;
		rank[u]++;
	}
}


int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.

	vector<int> parent(n+1);
	vector<int> rank(n+1,0);

	for(int i = 0 ; i <= n; i++){
		parent[i] = i;
	}

	sort(graph.begin(), graph.end(), cmp);
	int total = 0;
	
	for(int i = 0 ; i < m; i++){
		int u = findParent(parent,graph[i][0]);
		int v = findParent(parent,graph[i][1]);
		int w = graph[i][2];

		if(u != v){
			total += w;
			makeunion(parent, rank, u, v);
		}
	}

	return total;

}
