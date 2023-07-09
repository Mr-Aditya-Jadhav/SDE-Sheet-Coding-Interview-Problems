//https://www.codingninjas.com/studio/problems/size-of-largest-bst-in-binary-tree_8230743?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
class nodeval{
    public:
    int maxi;
    int mini;
    bool isbst;
    int size;
};
nodeval f(TreeNode<int>* root, int &ans){
    if(!root){
        return {INT_MIN, INT_MAX, 1, 0};
    }

    nodeval left = f(root->left, ans);
    nodeval right = f(root->right, ans);

    nodeval curr;
    curr.maxi = max(right.maxi,root->data);
    curr.mini = min(left.mini,root->data);
    curr.size = right.size + left.size + 1;
    if(right.isbst && left.isbst && (left.maxi < root->data && root->data < right.mini)){
        curr.isbst = 1;
    }
    else{
        curr.isbst = 0;
    }

    if(curr.isbst){
        ans = max(ans, curr.size);
    }

    return curr;

}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    int maxsize = 0;
    nodeval temp = f(root,maxsize);
    return maxsize;
}
