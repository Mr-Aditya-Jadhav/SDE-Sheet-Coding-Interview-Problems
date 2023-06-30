//https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
       vector<int>hash(123,0);
       for(auto it: s){
           hash[(int)(it)]++;
       }
       for(auto it: t){
           hash[(int)(it)]--;
           if(hash[(int)(it)] < 0){
               return false;
           }
       }

       return true;
       
    }
};
