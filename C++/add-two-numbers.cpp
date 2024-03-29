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
    //article https://leetcode.com/problems/add-two-numbers/discuss/1836671/C%2B%2B-or-easy-solution-or-14-lines-and-explanation
    //FB post https://www.facebook.com/groups/1451299754892511/posts/5140641069291676/
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //return answer1(l1,l2);
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;
        int carry = 0;
        while(l1!=nullptr || l2!=nullptr) {
            int v1 = (l1!=nullptr)?l1->val:0;
            int v2 = (l2!=nullptr)?l2->val:0;            
            int sum = v1+v2+carry;
            carry = sum/10;
            head = head->next = new ListNode(sum%10);
            l1=(l1!=nullptr)?l1->next:l1;
            l2=(l2!=nullptr)?l2->next:l2;
        }
        if(carry==1) head->next = new ListNode(1);
        return dummy->next;
    }
    ListNode* answer1(ListNode* l1, ListNode* l2) {
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