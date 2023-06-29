//https://www.codingninjas.com/studio/problems/longest-common-prefix_8230847?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 

int atoi(string s) {

    // Write your code here.

    bool flag = true;

        int digit=0;

        for(int i=0;i<s.size();i++){

            int rem = (int)s[i]-48;

            if(rem == -3){

                flag = false;

            }

            else if(rem>=0 && rem<=9){

                digit= digit*10+rem;

            }

            else{continue; }

        }

 

        if(flag ==false)

            digit=-1*digit;

        

        return digit;

}
