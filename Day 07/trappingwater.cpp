//https://www.codingninjas.com/codestudio/problems/trapping-rain-water_8230693?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    long long tot = 0;
    int l = 0;
    int r = n-1;
    long long leftmax = 0;
    long long rightmax = 0;

    while(l <= r){
      if (arr[l] <= arr[r]) {
        if (leftmax <= arr[l])
          leftmax = arr[l];
        else
          tot += leftmax - arr[l];
        
        l++;
      }
      else{
          if(rightmax <= arr[r])
            rightmax = arr[r];
          else
            tot += rightmax - arr[r];

        r--;
      }
    }
    return tot;

}
