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
    //Space Complexity O(1)
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode();
        ListNode* head = ans;
        while( !(list1 == nullptr && list2 == nullptr)) {
            if(list1 == nullptr || list2 == nullptr) {
                ListNode* remain= list1==nullptr?list2:list1;
                head->next = remain;
                break;
            } else {
                ListNode* next_head = list1->val < list2->val?list1:list2;
                //printf("next_head->val = %d\n", next_head->val);
                if(next_head==list1) {
                    list1 = list1->next;
                } else {
                    list2 = list2->next;
                }
                head->next = next_head;
                next_head->next = nullptr;
                head = head->next;
            }
        }
        return ans->next;
    }

    ListNode* mergeTwoListsAnswerVer01(ListNode* list1, ListNode* list2) {
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