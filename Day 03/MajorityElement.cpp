//https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count = 0;
        int x = nums[0];
        for(int i = 0 ; i < (nums.size()); i++){
            if(nums[i] == x){
                count++;
                
            }else {
                count--;
                
            }

            if(count == 0){
                x = nums[i+1];
                count = 0;
            }
        }

        int rec;
        for(int i  = 0 ; i <  nums.size(); i++){
            if(nums[i] == x){
                rec++;
            }
        }

        if(rec >= floor(nums.size() / 2)) return x;
    return -1;
    }
};
