//https://www.codingninjas.com/studio/problems/day-29-k-max-sum-combinations_8230768?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &A, vector<int> &B, int N, int K){
	// Write your code here.
	sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    vector<int>ans;
    priority_queue<pair<int,pair<int,int>>>pq;
    set<pair<int,int>>s;
    
    pq.push({A[N-1]+B[N-1],{N-1,N-1}});
    s.insert({N-1,N-1});
    
    while(K--){
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        ans.push_back(pq.top().first);
        pq.pop();
        
        if(s.find({x-1,y}) == s.end()){
            pq.push({A[x-1]+B[y],{x-1,y}});
            s.insert({x-1,y});
        }
        if(s.find({x,y-1}) == s.end()){
            pq.push({A[x]+B[y-1],{x,y-1}});
            s.insert({x,y-1});
        }
    }
    return ans;
}


    
