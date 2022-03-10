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
    //https://leetcode.com/problems/add-two-numbers-ii
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse_list(l1);
        l2 = reverse_list(l2);
        
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;
        int sum = 0;
        while(l1!=nullptr || l2!=nullptr || sum != 0) {
            int v1 = (l1!=nullptr)?l1->val:0;
            int v2 = (l2!=nullptr)?l2->val:0;            
            sum += v1+v2;
            head = head->next = new ListNode(sum%10);
            sum /= 10;
            l1=(l1!=nullptr)?l1->next:l1;
            l2=(l2!=nullptr)?l2->next:l2;
        }
        return reverse_list(dummy->next);
    }
private:
    ListNode* reverse_list(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next;
        while(head!=nullptr) {
            next = head->next;
            head->next = prev;        
            prev = head;
            head = next;            
        }
        return prev;
    }
};