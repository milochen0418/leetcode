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
    //https://leetcode.com/problems/sort-list/
public:
    ListNode* sortList(ListNode* head) {
        ListNode* node = head;
        int base = 1;
        ListNode* l = node;
        ListNode* r = node->next;
        int cnt;
        
        while(true) {
            cnt=0; while(r!=nullptr && cnt++<base) r = r->next;
            if(r == nullptr) break;
            
            merge_list(l, r, cnt);
            
            cnt=0; while(l!= nullptr && cnt++<base) l = l->next;
            if(l == nullptr) base*=2;
        }
        return head;        
    }

    ListNode* get_prev_node(ListNode* head, ListNode* target){
        ListNode *node = head;
        ListNode *prev_node = nullptr;
        while(node != nullptr) {
            prev_node = node;
            node=node->next;
        }
        return prev_node;
    }
    void merge_list(ListNode* left, ListNode* right, int count){
        ListNode * l = left;
        ListNode * r = right;
        int lcnt = 0;
        int rcnt = 0;
        //Refer https://www.geeksforgeeks.org/in-place-merge-sort/
        while(! (lcnt > count && rcnt > count) ) {
            int l_val = lcnt > count ? INT_MAX : l->val;
            int r_val = rcnt > count ? INT_MAX : r->val;
            if(l_val < r_val) {
                l = l->next;
            } else {
                //l->next
            }
            
        }
    }
};