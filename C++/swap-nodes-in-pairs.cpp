class Solution {
    //https://leetcode.com/problems/swap-nodes-in-pairs/
    //article https://leetcode.com/problems/swap-nodes-in-pairs/discuss/1774267/C%2B%2B-or-swap-or-O(N)
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* ans = head;
        while(!(head == nullptr || head->next == nullptr)  ){
            swap(head->val, head->next->val);
            head = head->next->next;
        }
        return ans;
    }
};