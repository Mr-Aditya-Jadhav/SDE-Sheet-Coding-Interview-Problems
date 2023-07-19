//https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pref = 1;
        int suff = 1;
        int maxi = INT_MIN;

        for(int i = 0 ; i < nums.size(); i++){
            if(!pref) pref = 1;
            if(!suff) suff = 1;

            pref *= nums[i];
            suff *= nums[nums.size() - i - 1];

            maxi = max(maxi, max(pref,suff));

        }

        return maxi;
    }
};
