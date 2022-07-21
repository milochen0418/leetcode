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
    //https://leetcode.com/problems/remove-linked-list-elements
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(val+1,head);
        ListNode* node = dummy;
        while(node->next) {
            if(node->next->val == val) {
                node->next = node->next->next;
            } else {
                node = node->next;
            }
        }
        return dummy->next;
    }
};