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
    //https://leetcode.com/problems/remove-nodes-from-linked-list/
public:
    ListNode* removeNodes(ListNode* head) {
        vector<ListNode*> v; 
        ListNode* node = head;
        while(node!=nullptr) {
            v.push_back(node);
            node = node->next;
        }
        vector<ListNode*> tmp;
        //for(int i = v.size()-1;i>=0;i--) {
        tmp.push_back(v[v.size()-1]);
        for(int i = v.size()-2;i>=0;i--) {        
            int val = tmp[tmp.size()-1]->val;
            if(v[i]->val>=val) {
                tmp.push_back(v[i]);
            }
        }
        reverse(tmp.begin(),tmp.end());
        head = tmp[0];
        node = tmp[0];
        for(int i = 1; i<tmp.size();i++) {
            node->next = tmp[i];
            node = node->next;
        }
        return head;
    }
};