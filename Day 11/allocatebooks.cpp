//https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{   
    public:
    bool ispossible(int a[], int n, int m, int mid){
        int student = 0;
        int alloc = 0;
        
        for(int i = 0 ; i < n; i++){
            if((alloc + a[i]) <= mid){
                alloc += a[i];
            }
            else{
                student++;
                alloc = a[i];
            }
        }
        
        return student<m;
    }
    
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {   
        if (M > N) return -1;
        //code here
        int low = 0;
        int high = 0;
        for(int i = 0 ; i < N; i++){
            low = max(low, A[i]);
            high += A[i];
        }
        
        int ans = -1;
        while(low <= high){
            int mid = (low+high)/2;
            
            if(ispossible(A, N, M, mid))
            {
                ans= mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    
    
   
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
