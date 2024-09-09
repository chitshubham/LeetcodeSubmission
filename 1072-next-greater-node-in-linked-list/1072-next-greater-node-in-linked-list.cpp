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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forw = head;
        while(curr!=NULL)
        {
            forw = forw->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        head= prev;
        vector<int>ans;
        stack<int>st;
        while(head!=NULL)
        {
            int val = head->val;
             if(st.empty()){
                st.push(val);
                ans.push_back(0);
             }
             else {
                if(st.top()>val) ans.push_back(st.top());
                else {
                    while(!st.empty()&&st.top()<=val) st.pop();
                    if(st.empty()) ans.push_back(0);
                    else ans.push_back(st.top());
                }
                 st.push(val);
             }
             head = head->next;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};