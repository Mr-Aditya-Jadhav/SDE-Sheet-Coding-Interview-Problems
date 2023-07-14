//https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
    
  private:
  void dfs(int node,int vis[], vector<int> &dfss, vector<int> adj[]){
        vis[node]=1;
        dfss.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,vis,dfss,adj);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        vector<int>dfss;
        dfs(0,vis,dfss,adj);
        return dfss;
    }
    
    
};
