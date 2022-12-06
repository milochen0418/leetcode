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
    //https://leetcode.com/problems/odd-even-linked-list
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* node1=head, *head1=node1;
        ListNode* node2=head->next, *head2=node2;
        int cnt = 0;
        ListNode* node1_prev = nullptr;
        while(node1 && node2) {
            node1->next = node2->next;
            node1_prev = node1;
            node1=node1->next;
            cnt++;
            if(node1 && node2) {
                node2->next = node1->next;
                node2=node2->next;
                cnt++;
            }
        }
        (cnt%2==0?node1:node1_prev)->next = head2;
        return head1;
    }
};