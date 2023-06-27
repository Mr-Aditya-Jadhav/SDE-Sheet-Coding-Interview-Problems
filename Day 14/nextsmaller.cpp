//https://www.codingninjas.com/studio/problems/next-smaller-element_8230814?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
   // Write your code here.
   stack <int> st;
   int temp = arr[n-1];
   st.push(arr[n-1]);
   arr[n-1] = -1;

   for(int i = n-2; i >= 0; i--){
       temp = arr[i];

       while((!st.empty()) && st.top() >= temp) st.pop();

       if(st.empty()) arr[i] = -1;
       else arr[i] = st.top();

       st.push(temp);
   }

   return arr;
}
