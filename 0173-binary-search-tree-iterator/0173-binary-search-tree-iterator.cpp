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
class BSTIterator {
public: 
    int i;
    int n;
    vector<int>arr; 
    BSTIterator(TreeNode* root) {
        i = 0;
         solve(root,arr);
         n = arr.size();
    }
     void solve(TreeNode* root , vector<int>&arr) 
     {
        if(!root) return ;
        solve(root->left , arr);
        arr.push_back(root->val);
        solve(root->right,arr);
     }
    int next() {
        return arr[i++];
    }
    
    bool hasNext() {
        if(i==n) return false;
         return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */