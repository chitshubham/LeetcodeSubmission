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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* head1=NULL;
        ListNode* tail = NULL;
        int sum = 0;
        head= head->next;
        while(head!=NULL)
        {
            sum+=head->val;
            if(head->val==0)
            {
                ListNode* curr  = new ListNode(sum);
                if(!head1) 
                {
                    head1 = curr;
                    tail = curr;
                }
                else 
                {
                    tail->next = curr;
                    tail=tail->next;
                }
                sum = 0;
            }
            head = head->next;
        }
        return head1;
    }
};