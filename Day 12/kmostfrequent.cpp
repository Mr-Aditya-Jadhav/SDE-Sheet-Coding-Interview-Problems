//https://www.codingninjas.com/studio/problems/k-most-frequent-elements_8230853?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{   
    typedef std::pair<int, int> pa;
    // Write your code here.
    priority_queue<pa, vector<pa>, greater<pa>>minh;
    unordered_map<int, int>mapp;
    for(int i = 0; i < n; i++){
        mapp[arr[i]]++;
    }

    for(auto it : mapp){
        pair <int, int>paa;
        paa.first = it.second;
        paa.second = it.first;
        minh.push(paa);
        if(minh.size() > k){
                minh.pop();
            }
        }

    vector<int> ans;
    while(minh.size() > 0){
        ans.push_back(minh.top().second);
        minh.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;

}
