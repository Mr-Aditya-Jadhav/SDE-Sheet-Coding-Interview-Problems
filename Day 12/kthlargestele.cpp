//https://leetcode.com/problems/kth-largest-element-in-an-array/solutions/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>maxheap;

        for(auto it: nums){
            maxheap.push(it);
        }

        int i = k-1;
        while(i > 0){
            maxheap.pop();
            i--;
        }

        return maxheap.top();
    }
};
