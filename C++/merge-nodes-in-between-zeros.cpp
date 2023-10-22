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
    //https://leetcode.com/problems/merge-nodes-in-between-zeros
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = new ListNode(0);
        ListNode* total_ans = ans;
        ListNode* iter = head;
        long long sum = 0;
        ListNode* prev_val_iter = nullptr;
        long long zero_cnt = 0; 
        while(iter != nullptr) {
            if(iter->val == 0) {
                //if(iter->next == nullptr) return ans; 
                if(zero_cnt>0) {
                    ans->val = sum;
                    if(iter->next == nullptr) return total_ans;
                    ans->next = new ListNode(0);
                    ans = ans->next;
                    sum = 0;
                }
                zero_cnt+=1;
            }
            sum += iter->val;
            iter = iter->next;
        }
        return total_ans;
    }
};