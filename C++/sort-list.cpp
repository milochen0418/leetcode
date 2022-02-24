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
        int len = 0; 
        //refer https://www.geeksforgeeks.org/in-place-merge-sort/
        ListNode* node = head;
        ListNode* start1_node = node;
        ListNode* start2_node = node;
        
        while(node != nullptr) {
            node = node->next;
            len++;
        }
        
        
        node = head;
        int cnt=0;
        while(node != nullptr) {
            ListNode* prev_node = node;
            node = node->next
            cnt++;
            if(cnt==len/2) {
                start2_node = node;
                prev_node->next = nullptr;
            }
        }
        
        //1 4 6 2 
        //2 5 6 7
        ListNode* node1 = start1_node;
        ListNode* node2 = start2_node; 
        while(node1 == nullptr && node2 == nullptr) { 
            if(node1 == nullptr) {
                    
            }
            
        }
        //TODO all of the code is not yet finished.
        
        
    }
};