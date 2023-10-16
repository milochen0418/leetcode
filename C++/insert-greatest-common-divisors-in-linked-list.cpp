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
    //https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* node = head;
        while(node) {
            if(node->next) {
                int val = gcd(node->val , node->next->val);
                ListNode *new_node = new ListNode(val);
                new_node->next = node->next;
                node->next = new_node;
                node = new_node->next;
            } else {
                break;
            }
        }
        return head;
    }
};