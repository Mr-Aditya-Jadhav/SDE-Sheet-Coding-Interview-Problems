//https://www.codingninjas.com/codestudio/problems/find-duplicate-in-array_8230816?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	unordered_map<int , int>map;
	for(auto it : arr){
		map[it]++;
	}
	for(auto it : map){
		if(it.second >= 2){
			return it.first;
		}
	}

	return -1;
}
