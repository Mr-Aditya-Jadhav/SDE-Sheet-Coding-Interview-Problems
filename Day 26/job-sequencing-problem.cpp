//https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

// simple greedy approach using priority_queue
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int N) 
    { 
        // your code here
        vector<vector<int>>v(N);
        priority_queue<int>pq;
        vector<int>ans(2,0);
        for(int i =0;i<N;i++)
        {
            v[arr[i].dead-1].push_back(arr[i].profit);
        }
        for(int i=N-1;i>=0;i--)
        {
            for(int j=0;j<v[i].size();j++)
            {
                pq.push(v[i][j]);
            }
            if(!pq.empty())
            {
                ans[0]++;
                ans[1] += pq.top();
                pq.pop();
            }
        }
        return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends
