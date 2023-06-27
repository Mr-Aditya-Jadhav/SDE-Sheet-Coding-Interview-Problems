//https://practice.geeksforgeeks.org/problems/aggressive-cows/0

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
bool ispossible(int mid, vector<int> &stalls, int k, int n){
    int cowCount = 1;
    int lastplaced = stalls[0];
    
    for(int i = 1 ; i < n ;i++){
        if((stalls[i]-lastplaced)>= mid){
            cowCount++;
            if(cowCount == k){
                return true;
            }
            lastplaced = stalls[i];
        }
    }
    
    return false;
}

class Solution {
public:

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(), stalls.end());
        int exlef = stalls[0];
        int exrig = stalls[0];
        for(int i = 0; i< n; i++){
            exlef = min(exlef, stalls[i]);
            exrig = max(exrig, stalls[i]);
        }
        int low = 0;
        int high = exrig;
        int ans = -1;
        while(low <= high){
            int mid = (low+high) / 2;
            if(ispossible(mid, stalls, k, n)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
