//https://leetcode.com/problems/flood-fill/

class Solution {
public:
    int delrow[4] = {-1,0,1,0};
    int delcol[4] = {0,1,0,-1};

    void dfs(int row,int col, int inicol,int newcol, vector<vector<int>>& image, vector<vector<int>>& ans)
    {   
        int n = ans.size();
        int m = ans[0].size();
        ans[row][col] = newcol;
        for(int i = 0 ; i < 4; i++){
            int nr = row + delrow[i];
            int nc = col + delcol[i];
            if(nr >=0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == inicol && ans[nr][nc] != newcol){
                dfs(nr,nc,inicol,newcol,image,ans);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicol = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr,sc,inicol,color,image,ans);

        return ans;
    }
};
