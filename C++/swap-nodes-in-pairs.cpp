class Solution {
    //https://leetcode.com/problems/swap-nodes-in-pairs/
    //article https://leetcode.com/problems/swap-nodes-in-pairs/discuss/1774267/C%2B%2B-or-swap-or-O(N)
    //FB post https://www.facebook.com/groups/1451299754892511/posts/5074225949266522/
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* ans = head;
        while(!(head == nullptr || head->next == nullptr)  ){
            swap(head->val, head->next->val);
            head = head->next->next;
        }
        return ans;
    }
    
    ListNode* answer_new(ListNode* head) {
        
        ListNode* dummy = new ListNode(0); 
        //dummy->next would be answer
        ListNode* head_prev = dummy; 
        head_prev->next = head;
        while(!(head == nullptr || head->next == nullptr)  ){
            //swap(head->val, head->next->val);
            ListNode* _head_prev = head_prev;
            ListNode* _head = head;
            ListNode* _head_next = head->next;
            ListNode* _head_next_next = head->next->next;
            
            //current status is 
            //_head_prev -> _head -> _head_next -> _head_next_next
            //And our purpose is to make the following status
            //_head_prev -> _head_next -> _head -> _head_next_next
            //So we just need to rewrite three next link as the following
            _head_prev->next = _head_next;
            _head_next->next = _head;
            _head->next = _head_next_next;
                        
            //After rewrite done, then keep going the loop by change status
            head = _head_next_next;
            head_prev = _head;
            
        }
        return dummy->next;
    }

};