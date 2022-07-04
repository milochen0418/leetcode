class Solution {
    //https://leetcode.com/problems/middle-of-the-linked-list
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* p1 = head, *p2=head;
        while(p2!=nullptr && p2->next!=nullptr) {
            p1=p1->next;
            p2=p2->next->next;
        }
        return p1;
        
    }
};