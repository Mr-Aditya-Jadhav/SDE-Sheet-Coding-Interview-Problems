//https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    bool dfs(int source, vector<int> &viscol, vector<vector<int>>& graph, int col){
        viscol[source] = col;
        for(auto it: graph[source]){
            if(viscol[it] == -1){
                if(!dfs(it, viscol, graph, !col)) return false;
            }
            else{
                if(viscol[it] == col){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int col = 0;
        int nodes = graph.size();
        vector<int> viscol(nodes,-1);
        for(int i = 0 ; i < nodes; i++){
            if(viscol[i] == -1){
            if(dfs(i,viscol,graph, col) == false) return false;
                }        
            }
        return true;
    }
};
