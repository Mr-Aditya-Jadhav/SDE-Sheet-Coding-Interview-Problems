//https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        stack<char>para;
        
        for(auto it :s){
            if(it == '(' || it == '[' || it == '{' ){
                para.push(it);
            }
            else{
                if(para.empty()) return false;
                if(para.top() == '(' && it == ')' || para.top() == '[' && it == ']' ||
                para.top() == '{' && it == '}') 
                {
                    para.pop();
                }
                else return false;
            }
    }

    if(para.empty()) return true;

    return false;
    }
};
