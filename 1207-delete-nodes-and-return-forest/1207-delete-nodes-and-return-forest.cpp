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
   TreeNode*  deleteNode(TreeNode* root , unordered_set<int>s , vector<TreeNode*>&res) 
   {
     if(root==NULL) 
    {
        return NULL;
     }
     root->left =  deleteNode(root->left ,s,res);
     root->right = deleteNode(root->right,s , res);
     if(s.find(root->val)!=s.end())
     {
        if(root->left)
        {
            res.push_back(root->left);
        }
        if(root->right)
        {
            res.push_back(root->right);
        }
        return NULL;
     } 
     else {
        return root;
     }
   }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int>s;
        for(int &num : to_delete)
        {
            s.insert(num);
        }
        vector<TreeNode*>res;
        deleteNode(root , s , res);
        if(s.find(root->val)==s.end()) 
        {
            res.push_back(root);
        }
        return res;
    }
};