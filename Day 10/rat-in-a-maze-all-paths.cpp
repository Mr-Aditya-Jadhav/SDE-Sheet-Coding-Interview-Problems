//https://www.codingninjas.com/studio/problems/rat-in-a-maze-all-paths_8230705?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 

bool check(int i,int j,int m,int n){

 

  if(i<0 || j<0 || i==m || j==n) return false;

  return true;

}

void f(vector<vector<int> > &maze,vector<vector<int>>&ans,int i,int j){

    int m=maze.size(),n=maze[0].size();

    if(i==m-1 && j==n-1){

      vector<int>temp;

      for(int i=0;i<m;i++){

        for(int j=0;j<n;j++){

          if(maze[i][j]==2) temp.push_back(1);

          else temp.push_back(0);

        }

      }

      ans.push_back(temp);

      return;

    }

    if(check(i+1,j,m,n) && maze[i+1][j]==1) {

      maze[i+1][j]=2;

      f(maze,ans,i+1,j);

      maze[i+1][j]=1;

    }

    if(check(i-1,j,m,n) && maze[i-1][j]==1) {

      maze[i-1][j]=2;

      f(maze,ans,i-1,j);

      maze[i-1][j]=1;

    }

    if(check(i,j+1,m,n) && maze[i][j+1]==1) {

      maze[i][j+1]=2;

      f(maze,ans,i,j+1);

      maze[i][j+1]=1;

    }

    if(check(i,j-1,m,n) && maze[i][j-1]==1) {

      maze[i][j-1]=2;

      f(maze,ans,i,j-1);

      maze[i][j-1]=1;

    }

    

}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){

  if(n==1 && maze[0][0]==1) return {{1}};

  vector<vector<int>>ans;

  vector<pair<int,int>>v;

  maze[0][0]=2;

  f(maze,ans,0,0);

  return ans;

}