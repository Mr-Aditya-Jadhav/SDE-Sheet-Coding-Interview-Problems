//https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        string toret = "";
        vector<string>dict;
        int i = 0;
        while(s[i] == (int)(' '))
        {
            i++;
        }
        
        for(; i < s.size();){
            string word = "";
            while(s[i] != (int)(' ') && i < s.size())
            {
                word += s[i];
                i++;
            }
            dict.push_back(word);
             while(s[i] == (int)(' ') && i < s.size())
            {
            i++;
            }
        }
        for(int j = dict.size() - 1; j >= 0; j--){
            toret += dict[j];
            if(j == 0) break;
            toret += " ";
        }

        return toret;

    }
};