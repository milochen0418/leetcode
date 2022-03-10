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
    //https://leetcode.com/problems/add-two-numbers/
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* ans = nullptr;
        ListNode* head = nullptr;
        int carry = 0;
        while(l1!=nullptr || l2!=nullptr) {
            int v1 = l1 == nullptr ? 0 : l1->val;
            int v2 = l2 == nullptr ? 0 : l2->val;
            int sum = v1+v2+carry;
            carry = sum/10;
            if(head!=nullptr) {
                head->next = new ListNode(sum%10);
                head = head->next;
            } else {
                head = new ListNode(sum%10);
                ans = head;
            }
            if(l1!=nullptr) l1=l1->next;
            if(l2!=nullptr) l2=l2->next;
        }
        if(carry==1) {
            head->next = new ListNode(1);
        }

        return ans==nullptr?new ListNode(0):ans;
    }
};