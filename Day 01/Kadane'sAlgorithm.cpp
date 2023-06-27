//https://www.codingninjas.com/codestudio/problems/maximum-subarray-sum_8230694?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    if( n == 0){
        return 0;
    }

    long long cursum = 0;
    long long maxsum = 1e-9;

    for(int i = 0; i<n ; i++ ){
        cursum = cursum + arr[i];
        maxsum = max(maxsum, cursum);

        if(cursum < 0){
            cursum = 0;
        }
    }

    return maxsum;

}



