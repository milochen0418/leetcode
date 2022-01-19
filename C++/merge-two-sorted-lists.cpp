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
    //https://leetcode.com/problems/merge-two-sorted-lists
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *list = nullptr;
        ListNode *head = nullptr;
        while(!(list1 == nullptr && list2 == nullptr)) {
            int val = 0;
            int list1_val = list1 == nullptr ? INT_MAX : list1->val;
            int list2_val = list2 == nullptr ? INT_MAX : list2->val;
            if( list1_val < list2_val) {
                val = list1_val;
                list1 = list1->next;
            } else if( list1_val >= list2_val){
                val = list2_val;
                list2 = list2->next;
            }
            
            if(list == nullptr) {
                head = list = new ListNode(val);
            } else {
                list = list->next = new ListNode(val);
            }
        }
        return head;
    }
};