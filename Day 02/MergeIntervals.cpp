//https://www.codingninjas.com/codestudio/problems/merge-intervals_8230700?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(auto it: intervals){
            if(it[0] <= ans.back()[1]){
                ans.back()[1] = max(ans.back()[1] , it[1]);
            }else{
                ans.push_back(it);
            }
        }
         return ans;
}
