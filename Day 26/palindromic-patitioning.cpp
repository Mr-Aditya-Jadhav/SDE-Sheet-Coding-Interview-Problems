//https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1

//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool check_palindrome(vector<char> &v)
    {
        for(int i=0; i<v.size()/2; i++)
            if(v[i]!=v[v.size()-1-i])
                return false;
        return true;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n=str.length();
        vector<int> dp(n, -1);
        dp[0]=0;
        for(int i=0; i<n; i++)
        {
            vector<char> v;
            int ans=INT_MAX;
            
            for(int k = i; k>=0; k--)
            {
                v.push_back(str[k]);
                if(check_palindrome(v))
                    (k==0)?(ans=0):(ans = min(ans, dp[k-1]+1));
            }
            dp[i]=ans;
        }
        return dp.back();
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
