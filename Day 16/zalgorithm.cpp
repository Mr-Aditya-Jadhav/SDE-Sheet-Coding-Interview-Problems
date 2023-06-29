//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

class Solution {
public:
    int strStr(string haystack, string needle) {
       
        int strlen = haystack.size();
        int patlen = needle.size() ;

        string s = needle + "#" + haystack;
        vector<int>z;
        int i = 0;
        while(i < s.size()){
            if(i <= patlen){
                z.push_back(0);
            }
            else{
                int left = 0,right = 0;
                if(s[left] == s[right]){
                    right = i;
                }
                while(s[left] == s[right] && right < s.size()){
                    left++;
                    right++;
                }
                z.push_back(left);
            }
            i++;
        } 
        
        for(i = 0 ;i < s.size(); i++){
            
            if(z[i] == patlen){
                return i-patlen-1;
            } 

          
        }

          return -1;
            
        }
};
