//https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int f(int i , int j, string &word1, string &word2,vector<vector<int>> &dp){
        

        if(j < 0) return i+1;
        if(i < 0) return j+1;
            
        if(dp[i][j] != -1) return dp[i][j];
        
        if(word1[i] == word2[j]){
           return dp[i][j] = f(i-1,j-1,word1,word2,dp);
        }
        
        return dp[i][j] =  1+ min( f(i,j-1,word1,word2,dp), 
                              min( f(i-1,j,word1,word2,dp),
                                   f(i-1,j-1,word1,word2,dp)));

    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return f(word1.size()-1, word2.size()-1,word1,word2,dp);
    }
};
