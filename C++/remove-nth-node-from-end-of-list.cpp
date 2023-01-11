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
    //https://leetcode.com/problems/remove-nth-node-from-end-of-list
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = head;
        int m = 0;
        while(node) {
            m++;
            node=node->next;
        }
        //there are m number of node here.
        
        int removed_idx = m-n, idx = 0;
        if(removed_idx==0) return head->next;
        node =head;
        while(node) {
            if(idx==removed_idx-1) {
                node->next =node->next->next;
                break;    
            }
            node=node->next;
            idx++;
        }
        return head;
    }
};