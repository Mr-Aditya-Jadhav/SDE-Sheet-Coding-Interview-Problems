//https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        set<int>hashset;

        for(auto it: nums){
            hashset.insert(it);
        }

        int longestStreak = 0;

  for (int num: nums) {
    if (!hashset.count(num - 1)) {
      int currentNum = num;
      int currentStreak = 1;

      while (hashset.count(currentNum + 1)) {
        currentNum += 1;
        currentStreak += 1;
      }

      longestStreak = max(longestStreak, currentStreak);
    }
  }

  return longestStreak;
    }
};
