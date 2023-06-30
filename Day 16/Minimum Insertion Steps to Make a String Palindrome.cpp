//https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

class Solution {
public:
       int minInsertions(string s) {
        string r = s;
        int si = s.size();
        reverse(r.begin(), r.end());
        vector<vector<int>> dp(si+1,vector<int>(si+1,-1));

        for(int i = 0 ; i <= si; i++) if(dp[0][i] == 0) dp[i][0] = 0;
        for(int i = 0 ; i <= si; i++) if(dp[i][0] == 0) dp[0][i] = 0;

        for(int x = 1; x <=si; x++){
            for(int y = 1; y <= si; y++){
            if(s[x-1] == r[y-1]){
                dp[x][y] = 1+ dp[x-1][y-1];
                    }
            else{
                dp[x][y] = max(dp[x][y-1], dp[x-1][y]);
                }
            }

        }

        int pali = dp[si][si];
        
        return si-pali-1;
        
    }
};
