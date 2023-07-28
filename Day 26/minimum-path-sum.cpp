//https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int f(int i, int j, int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {   
        if(dp[i][j] != -1) return dp[i][j];

        if(i == row-1 && j == col-1)
        {
            return grid[i][j];
        }
        if(i == row || j == col)
        {
            return 1e9;
        }

       
        int right = grid[i][j] + f(i,j+1,row,col,grid,dp);
        int botto = grid[i][j] + f(i+1,j,row,col,grid,dp);
        

        return dp[i][j] = min(right,botto);
    }
    int minPathSum(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row+1, vector<int>(col+1,-1));
        return f(0,0,row,col,grid,dp);
    }
};
