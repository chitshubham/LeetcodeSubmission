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
   void solve(TreeNode* root, int& val ) 
   {
    if(!root) return;
    if(!root->left && !root->right ) 
    {
     val = val+root->val;
     root->val = val;
     return;
    }
   
    solve(root->right,val);
    val = val+root->val;
    root->val = val;
     
    solve(root->left,val);
   }
    TreeNode* bstToGst(TreeNode* root) {
        int val = 0;
        solve(root,val);
        return root;
    }
};