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
    void solve(TreeNode* root, int targetSum , vector<int>res , vector<vector<int>>&ans) 
    {
        if(!root ){
            return;
         }
         if(!root->left && !root->right ) 
         {
            if(targetSum-root->val==0) 
            {
                res.push_back(root->val);
                ans.push_back(res);  
            }
         return;
         }
         res.push_back(root->val);
         solve(root->left ,targetSum-root->val,res,ans);
         solve(root->right,targetSum-root->val, res,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>res;
        vector<vector<int>>ans;
        solve(root,targetSum ,res,ans);
        return ans;

    }
};