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
    //https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list
public:
    int pairSum(ListNode* head) {
        vector<int> v;
        while(head) {
            v.push_back(head->val);
            head = head->next;
        }
        int n = v.size();
        int maxv = 0;
        for(int i = 0;i<n/2;i++) {
            int twin_sum = v[i] + v[n-1-i];
            maxv = max(maxv, twin_sum);
        }
        return maxv;
    }
};