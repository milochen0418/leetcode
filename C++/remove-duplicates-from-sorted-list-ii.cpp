class Solution {
    //https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
public:
    ListNode* deleteDuplicates(ListNode* head) {
        int DUMMY_VAL = -111;
        if(head ==nullptr) return nullptr;
        ListNode*dummy=new ListNode(DUMMY_VAL);
        dummy->next = head;
        ListNode* begin_node = dummy;
        int duplicates = 1;
        int duplicdate_val = DUMMY_VAL;
        head = dummy;
        
        while(head != nullptr) {
            if(head->next == nullptr || head->next->val != duplicdate_val) {
                if(duplicates > 1) {
                    begin_node->next = head->next;
                } else {
                    begin_node = head;
                }
                if(head->next == nullptr) break;
                duplicates = 1;
                duplicdate_val = head->next->val;
            } else {
                duplicates++;
            }
            head = head->next;
        }
        return dummy->next;
    }
};