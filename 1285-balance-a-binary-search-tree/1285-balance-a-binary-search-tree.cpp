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
    void constructArray(TreeNode*root, vector<int>&arr) 
    {
        if(!root) return ;
        constructArray(root->left , arr);
        arr.push_back(root->val);
        constructArray(root->right,arr);
    }
    TreeNode* constructTree(vector<int>arr,int start,int end )
    {
        if(start>end) return NULL;
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(arr[mid]);
       root->left = constructTree(arr,start,mid-1);
       root->right = constructTree(arr,mid+1,end);
       return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>arr;
        constructArray(root,arr);
        TreeNode* ans = constructTree(arr,0,arr.size()-1);
        return ans;
    }
};
auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();