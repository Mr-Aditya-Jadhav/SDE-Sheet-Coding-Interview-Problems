//https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1


/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
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
            if(nodes.find(v) == nodes.end()){
                nodes[v] = temp;    
            }
            
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
