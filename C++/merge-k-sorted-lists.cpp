class Solution {
    //https://leetcode.com/problems/merge-k-sorted-lists
    //article https://leetcode.com/problems/merge-k-sorted-lists/discuss/1745676/C%2B%2B-or-priority_queue
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/5040154489340335/
public:
    struct compare {
        bool operator()(const ListNode*  a, const ListNode*  b) {
            return a->val > b->val ;
        }        
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        for(auto list: lists) if(list!=nullptr) q.push(list);
        
        ListNode* head = nullptr ;
        ListNode* node = nullptr;
        while(!q.empty()) {
            if(head==nullptr) {
                node = new ListNode();
                head = node;                
            } else {
                node->next = new ListNode();
                node = node->next;
            }
            ListNode* e = q.top();
            q.pop();
            if(e->next != nullptr) q.push(e->next);
            node->val = e->val;            
        }    
        
        return head;
    }
};

/* testcase 
[[]]
[[1,4,5],[1,3,4],[2,6]]
*/