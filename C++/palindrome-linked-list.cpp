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
    //article https://leetcode.com/problems/palindrome-linked-list/discuss/3028630/C%2B%2B-2-approaches-or-stack-and-array
public:
    bool isPalindrome(ListNode* head) {
        ListNode* node = head;
        vector<int> v;
        while(node) {
            v.push_back(node->val);
            node=node->next;
        }        
        node = head;
        while(node) {
            if(node->val != v.back()) return false;
            v.pop_back();
            node=node->next;
        }
        return true;
    }


    bool isPalindrome_vector(ListNode* head) {
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