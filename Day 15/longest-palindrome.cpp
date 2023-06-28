//https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string solve(string s,int i,int j){

        while(i>=0 && j<s.length() && s[i] == s[j]){
            i--;
            j++;
        }

        string r="";
        for(int m=i+1;m<j;m++){
            r.push_back(s[m]);
        }

        return r;

    }
    string longestPalindrome(string s) {
        string ansOddKa;
        string ansEvenKa;
        int LongestPalinSubstrLenO = INT_MIN;
        int LongestPalinSubstrLenE = INT_MIN;

        for(int i=0;i<s.length();i++){
            // substrings can be either of even or odd length;
            string OddPalinSubstr = solve(s,i,i);
            int currSubstrLenO = OddPalinSubstr.length();
            if(currSubstrLenO > LongestPalinSubstrLenO){
                LongestPalinSubstrLenO = currSubstrLenO;
                ansOddKa = OddPalinSubstr;
            }

            string EvenPalinSubstr = solve(s,i,i+1);
            int currSubstrLenE = EvenPalinSubstr.length();
            if(currSubstrLenE > LongestPalinSubstrLenE){
                LongestPalinSubstrLenE = currSubstrLenE;
                ansEvenKa = EvenPalinSubstr;
            }
        }

        if(LongestPalinSubstrLenE > LongestPalinSubstrLenO){
            return ansEvenKa;
        }
        else{
            return ansOddKa;
        }
    }
};
