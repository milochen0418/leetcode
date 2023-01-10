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
    //https://leetcode.com/problems/palindrome-linked-list
public:
    bool isPalindrome(ListNode* head) {
        ListNode* node = head;
        vector<int> v;
        while(node) {
            v.push_back(node->val);
            node=node->next;
        }
        int L=0, R=v.size()-1;
        while(L<=R) if(v[L++]!=v[R--])return false;
        return true;
    }
};