//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int f(int index,int W, int n, int* wt, int* val, vector<vector<int>> &dp){
        
        if(dp[index][W] != -1) return dp[index][W];
        
        if(index == n){
            return 0;
        }
        
        int prof = INT_MIN;
        if(W >= wt[index])
        {
            prof = val[index] + f(index+1,W-wt[index],n,wt,val,dp);
        }
        
        return dp[index][W] = max(prof,f(index+1, W, n, wt, val,dp));
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
       return f(0,W,n,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
