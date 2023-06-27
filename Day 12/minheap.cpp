//https://www.codingninjas.com/codestudio/problems/min-heap_4691801?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h> 
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int> toret;
    priority_queue<int, vector<int>, greater<int>>heap;
    for(auto it: q){
        if(it[0] == 0){
        heap.push(it[1]);
        }
        else{
            toret.push_back(heap.top());
            heap.pop();
        }
    }
    
    
    

    return toret;
   
}
