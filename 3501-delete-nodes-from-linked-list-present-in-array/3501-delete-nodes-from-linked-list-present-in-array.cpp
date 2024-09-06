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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* newHead = nullptr;
        ListNode* newTail = nullptr;
        map<int , bool>mp;
        for(int x : nums) 
        {
            mp[x] = true;
        }
        while(head!=NULL) 
        {
            if(!mp[head->val]) 
            {
                ListNode* temp = new ListNode(head->val,NULL);
                if(!newHead) {
                    newHead = temp;
                    newTail = temp;
                }
                else 
                {
                    newTail->next = temp;
                    newTail = newTail->next;
                }
            }
            head= head->next;
        }
        return newHead;
        
    }
};