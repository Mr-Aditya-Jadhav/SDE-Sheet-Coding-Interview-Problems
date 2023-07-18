//https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n = matrix.size();
	    for(int i = 0 ; i < n; i++){
	        for(int j = 0 ; j < n; j++){
	            if(matrix[i][j] == -1){
	                matrix[i][j] = 1e9;
	            }
	        }
	    }
	    
	    
	    for(int i = 0 ; i < n; i++){
	        for(int j = 0 ; j < n; j++){
	            for(int k = 0 ; k < n; k++){
	                matrix[j][k] = min(matrix[j][k] , matrix[j][i] + matrix[i][k]);
	            }
	        }
	    }
	   
	}
};
