//https://leetcode.com/problems/search-in-rotated-sorted-array/description/

// Binary search in rotated array
// Mr_Aditya_Jadhav

// Intuition
// for first as we have sorted array, even it is rotated it is a sorte array, so we can apply bianry search.

// Approach
// we will start doing usual binary search and we will find mid, 
// and the check is it left side already sorted or not, by checking with first element, 
// and if yes then we will chcek wether our target lies in left half or not, 
// if yes then we will shrunk or search space to the left half, and similar things we can do in right half too in the else block.

// Complexity
// Time complexity:
// O(long N)

// Space complexity:
// O(1)

// Code
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
