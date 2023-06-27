// https://www.codingninjas.com/codestudio/problems/set-matrix-zeros_8230862?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h>
void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	int col = 1;
	int coln = matrix[0].size();
	int rown = matrix.size();

	for(int i = 0; i < rown; i++ ){
		for(int j = 0; j< coln; j++){
			if(matrix[i][j] == 0){
				matrix[i][0] = 0;
				if( j != 0){
					matrix[0][j] = 0;
					
				}
				else{
					col = 0;
					
				}
			}
		}
	}
	
	for(int i = 1 ; i < rown ; i++)
		{
			for(int j = 1 ; j < coln; j++){
				if(matrix[i][j] != 0){
					if(matrix[0][j] == 0 || matrix[i][0] == 0){
						matrix[i][j] = 0;
					}
				}
			}
		}

	if(matrix[0][0] == 0){
		for(int j = 0;j < coln ;j++){
			matrix[0][j] = 0;
		}
	}

	if(col == 0){
		for(int i =0 ;i < rown ; i++){
			matrix[i][0] = 0;
		}
	}

	


	
}