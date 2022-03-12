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
    //https://leetcode.com/problems/rotate-list/
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr) return head;
        int len = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            len++;
            temp = temp->next;
        }
        if(k%len == 0) return head;
        int ans= k % len;
        int minus = len - ans - 1;
        temp = head;
        while(minus){
            temp=temp->next;
            minus--;
        }
        //temp
        ListNode* front = temp->next;
        temp->next = nullptr;
        temp = front;
        while(true){
            if(temp->next == nullptr) break;
            temp = temp->next;
        }
        temp->next = head;
        return front;
        
    }
};