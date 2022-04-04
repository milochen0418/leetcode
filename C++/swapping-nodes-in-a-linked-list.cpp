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
    //https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
public:
    ListNode* swapNodes(ListNode* head, int k) {
        return answer3(head,k);
        int n = 0;
        ListNode *node = head;
        while(node != nullptr) {
            node = node->next;
            n++;
        }
        ListNode*L, *R;
        
        node = head;
        int i = 0;
        
        while(node != nullptr) {
            if((i+1)==k) L = node;
            if(i==(n-k)) R = node;
            node = node->next;
            i++;
        }
        swap(L->val, R->val);
        return head;
    }
    
    ListNode* answer2(ListNode* head, int k) {
        int n = 0;
        ListNode *node = head;
        ListNode*L, *R=head;
        while(node != nullptr) {
            if(n+1==k) L=node;
            if(n+1>k) R=R->next;
            node = node->next;
            n++;
        }
        swap(L->val, R->val);
        return head;        
    }
    
    ListNode* answer3(ListNode* head, int k) {
        unordered_map<int,ListNode*> mp;
        int n = 0;
        ListNode *node = head;
        ListNode*L, *R=head;
        while(node != nullptr) {
            mp[n+1] = node;
            node = node->next;
            n++;
        }
        swap(mp[k]->val, mp[n-k+1]->val);
        return head;
    }    
};