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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* forw = curr->next;
        if(!forw) return {-1,-1};
        vector<int>ans;
        int i =2 ; 
        while(forw!=NULL)
        {
            if( (prev->val>curr->val && curr->val<forw->val) || (prev->val<curr->val && curr->val>forw->val) )
            {
                ans.push_back(i);

            }
            i++;
            prev = curr;
            curr = forw;
            forw = forw->next;
        }  
        if(ans.size()<=1) return {-1,-1};
        int mini = INT_MAX;
        for(int i =1 ; i<ans.size();++i)  
        {
            mini = min(ans[i]-ans[i-1],mini);
        }
         
        return {mini,ans[ans.size()-1]-ans[0]};
    }
};