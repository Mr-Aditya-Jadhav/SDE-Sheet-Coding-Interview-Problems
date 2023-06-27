//https://www.codingninjas.com/codestudio/problems/m-coloring-problem_8230777?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

bool ispossible(int node, int col, vector<vector<int>> &mat, vector<int> &color, int n){
    for(int i = 0 ; i< n; i++){
        if(node != i && mat[i][node] && color[i] == col) return false;
    }
    return true;
}


bool solve(int node, vector<vector<int>> &mat, int m, vector<int> &color, int n){
    if(node == n) return true;

    for(int col = 1; col <= m; col++){
        if(ispossible(node, col, mat, color, n)){
            color[node] = col;
            if(solve(node+1, mat, m, color, n)) return true;
            color[node] = 0;
        }
    }
    return false;
} 

string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n = mat.size();
    vector<int>color(n, 0);
    if(solve(0, mat, m, color, n)) return "YES";
    return "NO";
}
