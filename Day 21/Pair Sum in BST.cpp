//https://www.codingninjas.com/studio/problems/pair-sum-in-bst_8230756?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
void inorder(vector<int> &arr, BinaryTreeNode<int> *root){
        if(!root) return;

        inorder(arr,root->left);
        arr.push_back(root->data);
        inorder(arr,root->right);

    }
bool pairSumBst(BinaryTreeNode<int>* root, int k) {
        vector<int> arr;
        inorder(arr,root);
        int s = 0;
        int e = arr.size()-1;
        while(s < e){
            if(arr[s]+arr[e] == k){
                return true;
            }
            else if(arr[s]+arr[e] > k){
                e--;
            }
            else{
                s++;
            }
        }

        return false;
    }

