//https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while(start <= end){
            int mid = (start + end)/2;

            if(nums[mid] == target) return mid;
            else{

                if(nums[mid] >= nums[start]){
                    // left side is sorted
                    if(nums[start] <= target && nums[mid] >= target){
                        //taget lies in the range
                        end = mid-1;
                    }
                    else{
                        start = mid+1;
                    }
                }
                else{
                    //right side is sorted
                    if(nums[mid] <= target && nums[end] >= target){
                        //taget lies in the range
                        start = mid+1;
                    }
                    else{
                        end = mid-1;
                    }
                }

            }
        }

        return -1;
    }
};