//https://www.codingninjas.com/codestudio/problems/missing-and-repeating-numbers_8230733?challengeSlug=striver-sde-challenge&leftPanelTab=1


#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	pair<int, int>toret;
	unordered_map<int, int>map;
	for(auto it : arr){
		map[it]++;
	}
	for(int i = 1 ; i <= n ; i++){
		if(map[i] == 0){
			toret.first = i;

		}else if(map[i] == 2){
			toret.second = i;
		}
		else{
			continue;
		}
	}

	return toret;
	
}
