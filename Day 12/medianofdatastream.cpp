//https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    priority_queue<double>maxh;
    priority_queue<double,vector<double>,greater<double>>minh;
    //Function to insert heap.
    void insertHeap(int &num)
    {
        if(maxh.empty() || maxh.top()>=num) maxh.push(num);
        else minh.push(num);

        if(maxh.size()>minh.size()+1){
            minh.push(maxh.top());
            maxh.pop();
        }
        else if(maxh.size()<minh.size()){
            maxh.push(minh.top());
            minh.pop();
        }
        
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(minh.size()<maxh.size()) return maxh.top();
        else return ((minh.top()+maxh.top())/2);
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends
