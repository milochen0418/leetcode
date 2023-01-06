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
    //https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list
public:
    #define printf(...) empty_printf(__VA_ARGS__)
    #define empty_printf(...)
    
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        int cnt;
        ListNode* ans=head;
        
        while(head && head->next) {
            cnt = m;
            ListNode *node;
            while(head && --cnt>0) head=head->next;
            printf("move: head->val=%d\n", !head?-1:head->val);

            if(!head) break;
            cnt = n;
            node=head->next;
            while(node && node->next && --cnt>0) node=node->next;
        
            if(node)
                head->next = node->next;
        
            if(!head) break;
            
            if(head)head=head->next;
            printf("del: head->val=%d\n", !head?-1:head->val);
        }
        return ans;
        
        
    }
};