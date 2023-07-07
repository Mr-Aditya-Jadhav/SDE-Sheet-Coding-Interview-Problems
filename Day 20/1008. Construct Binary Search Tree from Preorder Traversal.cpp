//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* f(vector<int>&a, int &i, int ub){
        if(i == a.size()) return NULL;

        if(a[i] > ub) return NULL;

        TreeNode* root = new TreeNode(a[i]);
         i++;
         root->left = f(a,i,root->val);
         root->right= f(a,i,ub);

         return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return f(preorder, i, INT_MAX);
    }
};
