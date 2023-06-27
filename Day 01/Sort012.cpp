// https://www.codingninjas.com/codestudio/problems/sort-0-1-2_8230695?challengeSlug=striver-sde-challenge

//Dutch National flag algorithm

#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
   int count0;
   int count1;
  
   for(int i = 0; i< n; i++){
      if(arr[i] == 0){
         count0++;
      }
      else if(arr[i] == 1){
         count1++;
      }
      else{
         
      }
   }
   int j = 0;
   while(j < n){
      if(j < count0){
         arr[j] = 0;

      } else if (j < count0 + count1) {
        arr[j] = 1;
      } else {
        arr[j] = 2;
      }
      j++;
   }
}