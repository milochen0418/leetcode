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
    //https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr) return nullptr;
        ListNode* l1 = head;
        ListNode* l2 = head->next->next;
        
        while(l2 != nullptr && l2->next != nullptr) {
            l1 = l1->next;
            l2 = l2->next->next;
        }
        l1->next = l1->next->next;
        return head;
    }
};