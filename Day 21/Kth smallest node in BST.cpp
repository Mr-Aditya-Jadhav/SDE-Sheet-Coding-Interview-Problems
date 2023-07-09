//https://www.codingninjas.com/studio/problems/kth-smallest-node-in-bst_8230751?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void f(TreeNode<int>* root, int &count, int &ans, int k){
        if(!root) return;
        f(root->left,count,ans,k);
        count++;
        if(k == count){
            ans = root->data;
            return;
        }
        f(root->right,count,ans,k);
    }

int kthSmallest(TreeNode<int>* root, int k) {
        int count = 0;
        int ans = 0;
        f(root, count,ans,k);
        return ans;
    }

