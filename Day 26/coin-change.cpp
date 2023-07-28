//https://leetcode.com/problems/coin-change/

class Solution {
public:
int solve(vector<int>& coins,int V,vector<int>&dp)
{
 	  if(V==0)
	  return 0;
	  
	  if(V<0)
	  return INT_MAX;
	  
	  if(dp[V]!=-1)
	  {
	      return dp[V];
	  }
	  int mini=INT_MAX;
	  for(int i=0;i<coins.size();i++)
	  {
	      int ans=solve(coins,V-coins[i],dp);
	      if(ans!=INT_MAX)
	      mini=min(mini,ans+1);
	  }
	  dp[V]=mini;
	  return dp[V];
}



    int coinChange(vector<int>& coins, int amount)
     {
        vector<int>dp(amount+1,-1);
        int ans=solve(coins,amount,dp);
        if(ans==INT_MAX)
        return -1;
        else
        return ans;    

    }
};
