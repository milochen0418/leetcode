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
    //https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while(head !=nullptr)  {
            ans=ans*2+head->val;
            head = head->next;
        }
        return ans;
    }
};