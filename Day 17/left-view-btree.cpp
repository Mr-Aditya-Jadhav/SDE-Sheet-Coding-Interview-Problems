//https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1



/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
void trav(Node *root, int lev, vector<int> &ds){
    if(root == NULL) return;
    
    if(lev == ds.size()) ds.push_back(root->data);
    
    trav(root->left, lev+1, ds);
    trav(root->right, lev+1, ds);
}

vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ds;
   //ds.push_back(root->data);
   trav(root, 0, ds);
   
   return ds;
}
