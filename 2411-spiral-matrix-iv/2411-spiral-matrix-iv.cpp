/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
        int dr[4] = {0,1,0,-1};
        int dc[4] = {1,0,-1,0};
        int  row = 0 , col = 0, di = 0;
        while(head!=NULL)
        {
            ans[row][col]=head->val;
            int nrow = row + dr[di];
            int ncol = col + dc[di];
            // cout<<row<<" "<<col<<" "<<head->val<<endl;
            if(nrow>=0&&nrow<m && ncol>=0 &&ncol<n && ans[nrow][ncol]==-1 )
            {
                
                row = nrow;
                col = ncol;
            }
            else {
                di=(di+1)%4;
                row+=dr[di];
                col+=dc[di];
            }
            head= head->next;
        }
        return ans;
    }
};