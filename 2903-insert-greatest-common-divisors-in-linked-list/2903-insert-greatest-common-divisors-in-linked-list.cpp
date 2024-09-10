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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL || head->next == NULL ) return head;
        ListNode* prev = head;
        ListNode* forw = head->next;
        while(forw!=NULL){
        ListNode* temp  = new ListNode(__gcd(prev->val,forw->val));
        prev->next = temp;
        temp->next= forw;
        prev = forw;
        forw = forw->next;    
        }
        return head;
    }
};