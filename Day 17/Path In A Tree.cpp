//https://www.codingninjas.com/studio/problems/path-in-a-tree_8230860?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/
bool getPath(TreeNode<int> * root, vector < int > & arr, int x) {
	
  if (!root)
    return false;

  arr.push_back(root -> data);

  
  if (root -> data == x)
    return true;

  
  if (getPath(root -> left, arr, x) || getPath(root -> right, arr, x))
    return true;


  arr.pop_back();
  return false;
}


vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector < int > arr;
	getPath(root, arr, x);
  	return arr;
}
