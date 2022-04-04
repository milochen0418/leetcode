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
    //https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        ListNode *node = head;
        while(node != nullptr) {
            node = node->next;
            n++;
        }
        ListNode*L, *R;
        
        node = head;
        int i = 0;
        
        while(node != nullptr) {
            if((i+1)==k) L = node;
            if(i==(n-k)) R = node;
            node = node->next;
            i++;
        }
        swap(L->val, R->val);
        return head;
    }
};