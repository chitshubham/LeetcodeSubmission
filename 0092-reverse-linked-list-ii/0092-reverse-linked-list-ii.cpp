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
    ListNode* rev(ListNode* head){
        ListNode* prev = NULL;
        ListNode * curr = head;
        ListNode * forw = head;
        while(curr!=NULL){
            forw = forw->next;
             curr->next= prev;
             prev = curr;
             curr = forw;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* leftNode = NULL;
        ListNode* rightNode = NULL;
        ListNode* pleft = NULL;
        ListNode* pright = NULL;
        ListNode * curr = head;
        if(left==right) return head;
        int cnt = 1 ;
        while(curr!=NULL){
            if(cnt==left){
                leftNode = curr;
            }
            if(cnt == right ){
                rightNode = curr;
            }
            if(cnt == left - 1 ) pleft = curr;
            if(cnt == right+1) pright = curr;
             cnt++;
            curr = curr->next;
        }
        if(pleft==NULL&& pright == NULL) return rev(head);
        rightNode->next = NULL;
        ListNode* temp = rev(leftNode);
        if(pleft!=NULL) 
         pleft->next = rightNode; 

        leftNode->next = pright;
        if(pleft==NULL) return rightNode;
         return head;
    }
};