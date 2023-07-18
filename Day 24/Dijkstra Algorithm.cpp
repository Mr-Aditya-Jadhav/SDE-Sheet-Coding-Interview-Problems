//https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minq;
        
        vector<int>distance(V,INT_MAX);
        distance[S] = 0;
        
        minq.push({0,S});
        
        while(!minq.empty()){
            auto p = minq.top();
            minq.pop();
            int dist = p.first;
            int node = p.second;
            
            for(auto it: adj[node]){
                int newdist = it[1];
                int newnode = it[0];
                
                if((newdist+dist) < distance[newnode]){
                    distance[newnode] = (newdist + dist) ;
                    minq.push({distance[newnode],newnode});
                }
            }
            
        }
        
        
        return distance;
    }
};
