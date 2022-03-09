class Solution {
    //https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head ==nullptr) return nullptr;
        const int DUMMY_VAL = -111;
        ListNode* node;
        ListNode* begin_node;
        ListNode* dummy = new ListNode(DUMMY_VAL);
        
        dummy->next = head;        
        node = dummy;
        begin_node = dummy;
        int duplicates = 1;
        int duplicdate_val = DUMMY_VAL;

        while(node != nullptr) {
            if(node->next == nullptr || node->next->val != duplicdate_val) {
                if(duplicates > 1) {
                    begin_node->next = node->next;
                } else {
                    begin_node = node;
                }
                if(node->next == nullptr) break;
                duplicates = 1;
                duplicdate_val = node->next->val;
            } else {
                duplicates++;
            }
            node = node->next;
        }
        return dummy->next;
    }
};