//https://leetcode.com/problems/median-of-two-sorted-arrays/description/

// naive but easy solution with O(n+m) TC using merge sort logic.
// Mr_Aditya_Jadhav
// 2
// 2 hours ago
// C++
// Merge Sort
// Intuition
// Pretty easy question, don't know why they marked it as a Hard one, it is just simple merged sort's merge section.

// Approach
// we will implement merge sort's merge fucntion with given two arrays as, initilize two pointers one, two and now we will run while loop, unless both of them goes out of size of both the arrays resepectively,
// once they go out of index, then it is a clear that one the array is exhausted so now we will itertae over remaiing again.
// and in the last we will return median differnetly for both even sized merged arry and odd sized merged array.as return type is double.

// Complexity
// Time complexity:
// O(n+m)

// Space complexity:
// O(n+m)

// Code
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> merged;
        int one = 0;
        int two = 0;
        while(one < nums1.size() && two < nums2.size())
        {
            if(nums1[one]<= nums2[two]){
                merged.push_back(nums1[one]);
                one++;
            }
            else{
                merged.push_back(nums2[two]);
                    two++;
                }
            }
        

        while(one < nums1.size()){
            merged.push_back(nums1[one]);
            one++;
        }
        
        while(two < nums2.size()){
            merged.push_back(nums2[two]);
            two++;
        }

        if(merged.size() % 2 == 0)
        {
            int mid = (merged.size() -1) / 2;
            return ((merged[mid] + merged[mid+1])/2);
        }
        else
        {
        return merged[(merged.size()-1)/2];
        }

    }
};
