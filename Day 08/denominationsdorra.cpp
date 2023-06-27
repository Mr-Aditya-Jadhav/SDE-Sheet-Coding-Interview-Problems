//https://www.codingninjas.com/codestudio/problems/find-minimum-number-of-coins_8230766?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    
    int count = 0;
    if(amount/1000 > 0){
        count = count + (amount/1000);
        amount = amount%1000;
    }
    if(amount/500 > 0){
        count = count + (amount/500);
        amount = amount%500;
    }
    
    if(amount/100 > 0){
        count = count + (amount/100);
        amount = amount%100;
    }
    
    if(amount/50 > 0){
        count = count + (amount/50);
        amount = amount%50;
    }
    
    if(amount/20 > 0){
        count = count + (amount/20);
        amount = amount%20;
    }
    
    if(amount/10 > 0){
        count = count + (amount/10);
        amount = amount%10;
    }

    if(amount/5 > 0){
        count = count + (amount/5);
        amount = amount%5;
    }

    if(amount/2 > 0){
        count = count + (amount/2);
        amount = amount%2;
    }


    if(amount > 0){
        count++;
    }

    return count;
    
    // int count = 0;
    // int i = 8;
    // int denom[9] = {1,2,5,10,20,50,100,500,1000};
    // while(amount > 0){
    //     if(amount/denom[i] == 0){
    //         i--;
    //     }
    //     count += amount/denom[i];
    //     amount = amount%denom[i];
    //     i--;
    // } 

    // return count;


}
