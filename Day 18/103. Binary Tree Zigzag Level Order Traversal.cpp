//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;

        bool ltor = 1;
        queue<TreeNode *> node;
        node.push(root);

        while(!node.empty()){
            int size = node.size();
            vector<int>row(size,0);
            
            for(int i =0 ; i <size; i++){
                
                auto p = node.front();
                node.pop();
                
                int index = ltor ? i : (size-i-1);

                row[index] = p->val;

                if(p->left){
                    node.push(p->left);
                }
                if(p->right){
                    node.push(p->right);
                }
            }

            res.push_back(row);
            ltor = !ltor;   
        }

        return res;
    }
};
