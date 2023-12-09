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
    //https://leetcode.com/problems/double-a-number-represented-as-a-linked-list
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode*node = head;
        while(node){
            int v = (node->val)*2;
            if(node->next && node->next->val>=5) v+=1;
            node->val = v;
            node=node->next;
        }
        if(head->val>=10) {
            node = new ListNode(1, head);
            head = node;
        }
        node = head;
        while(node) {
            node->val%=10;
            node=node->next;
        }
        return head;
    }
};