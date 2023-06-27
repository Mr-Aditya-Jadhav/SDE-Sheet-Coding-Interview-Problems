//https://www.codingninjas.com/codestudio/problems/subset-sum_8230859?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
void func(int index, int sum, vector<int> &toret, int n, vector<int> &num){
    if(index == n){
        toret.push_back(sum);
        return;
    }
    
    func(index+1,sum + num[index], toret, n, num);

    

    func(index+1, sum, toret, n, num);
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    int sum = 0;
    int n = num.size();
    vector<int>toret;
    func(0,0,toret,n,num);

    sort(toret.begin(), toret.end());

    return toret;

    
}
