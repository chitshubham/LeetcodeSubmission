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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<double>ans;
        while(!q.empty())
        {
            int n = q.size();
            long long  totalSum = 0 ;
            for(int i = 0; i<n;++i)
            {
                TreeNode* temp = q.front();
                q.pop();
                totalSum += temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);

            }
            double res =(double) totalSum / (double) n;
            ans.push_back(res); 
        }
        return ans;
    }
};