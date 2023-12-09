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
    //article https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/discuss/4382630/C%2B%2B-or-simple-8-lines-One-Pass-O(N)-solution
    //FB post https://www.facebook.com/groups/1451299754892511/posts/7163704600318636/
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode*node = head;
        if(head->val>=5) head = new ListNode(1, head);
        while(node){
			int carry = (node->next && node->next->val>=5);
            node->val = (2*(node->val)+carry)%10;
            node=node->next;
        }
        return head;
    }
    ListNode* doubleIt_v01(ListNode* head) {
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