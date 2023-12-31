//https://practice.geeksforgeeks.org/problems/topological-sort/1

class Solution
{
	public:
	//Function to return list containing vertices in Topological order

	 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> indegree(V,0);
        for(int i = 0 ; i < V; i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
    
        for(int i = 0 ; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int p = q.front();
            q.pop();
            ans.push_back(p);
            for(auto it: adj[p]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
    
        return ans;
	}
};
