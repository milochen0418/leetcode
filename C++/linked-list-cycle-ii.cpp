/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    //https://leetcode.com/problems/linked-list-cycle-ii
    //unordered_set can refer the code in 
    //- find-all-numbers-disappeared-in-an-array.cpp
    //- maximum-number-of-words-you-can-type.cpp
    //Space O(1) algorithm can refer 
    //Floyd's cycle detection algorithm  youtube.com/watch?v=PvrxZaH_eZ4
    //Or refer the solution https://leetcode.com/problems/linked-list-cycle-ii/solution/
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        ListNode *p = head;
        
        while(p != nullptr) {
            if(set.find(p) != set.end()) {
                return p;
            } else {
                set.insert(p);
            }
            p = p->next;
        }
        return nullptr;   
    }
};