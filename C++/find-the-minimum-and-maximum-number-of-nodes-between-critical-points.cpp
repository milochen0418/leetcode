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
    //https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v,c,ans = {-1,-1};
        
        while(head) {
            v.push_back(head->val);
            head = head->next;
        }
        for(int i = 1;i<v.size()-1;i++){
            if((v[i-1]<v[i] && v[i+1]<v[i]) || 
               (v[i-1]>v[i] && v[i+1]>v[i]) ) {
                c.push_back(i);
            }
        }
        if(c.size()>=2) {
            int max_dist = c.back() - c.front();
            int min_dist = INT_MAX;
            for(int i = 1; i<c.size();i++) 
                min_dist=min(min_dist, c[i]-c[i-1]);
            return {min_dist,max_dist};
        }
        return {-1,-1};
        
    }
};