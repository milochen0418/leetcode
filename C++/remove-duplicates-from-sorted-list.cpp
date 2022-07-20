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
    //https://leetcode.com/problems/remove-duplicates-from-sorted-list
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans = head;
        while(head) {
            if(head->next && head->val == head->next->val) {
                head->next = head->next->next;
            } else {
                head=head->next;
            } 
        }
        return ans;
    }
};