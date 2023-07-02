//https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        if(root == NULL) return ans;
        
        queue<pair<Node*,int>> q;
        map<int,Node*> nodes;
        
        q.push({root,0});
        
        while(!q.empty()){
            auto p = q.front();
            Node * temp = p.first;
            int v = p.second;
            q.pop();
            nodes[v] = temp;
            
            if(temp->left != NULL){
                q.push({temp->left, v-1});
            }
            
            if(temp->right != NULL){
                q.push({temp->right,v+1});
            }
        }
        
        for(auto it:nodes){
            ans.push_back(it.second->data);
            }
        return ans;
    }
};
