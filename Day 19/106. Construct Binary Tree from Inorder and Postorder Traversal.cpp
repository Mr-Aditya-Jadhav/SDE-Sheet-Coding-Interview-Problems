//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    TreeNode* sol(vector<int>& post, vector<int>& in,int a,int b,int j){
        if(a==b)return NULL ;
        int x =-1;
        for(int i=a ;i<b ;i++){
            if(post[j] == in[i]){
                x= i ;
                break ;
            }
        }
        TreeNode *root = new TreeNode() ;
        root->val = in[x] ;
        if(x!=0){
            root->left= sol(post,in,a,x,j-(b-x)) ;
        }
        root->right = sol(post,in,x+1,b,j-1) ;
        return root ;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        
        int n = in.size() ;
        TreeNode* root = sol(post,in,0,n,n-1) ;
        return root ;
    }
};
