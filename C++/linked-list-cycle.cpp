/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    //https://leetcode.com/problems/linked-list-cycle
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        while(head!=nullptr) {
            if(s.find(head) !=s.end()) return true;
            s.insert(head);
            head = head->next;
        }
        return false;      
    }
};