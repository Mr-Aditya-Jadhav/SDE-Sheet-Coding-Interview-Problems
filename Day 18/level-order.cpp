//https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            vector<TreeNode *> temp;
            vector<int> toret;
            while(!q.empty()){
                temp.push_back(q.front());
                toret.push_back(q.front()->val);
                q.pop();
            }
            for(auto it: temp){
                if(it->left != NULL){
                    q.push(it->left);
                }
                
                if(it->right != NULL){
                    q.push(it->right);
                }
            }
            ans.push_back(toret);
        }

        return ans;
    }
};
