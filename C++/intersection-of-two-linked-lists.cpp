class Solution {
    //https://leetcode.com/problems/intersection-of-two-linked-lists/
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //figure length of headA is n;
        ListNode* head = headA;
        int n = 0;
        while(head != nullptr) {
            n++;
            head=head->next;
        }
        
        //figure length of headB is m
        head = headB;
        int m = 0;
        while(head != nullptr) {
            m++;
            head=head->next;
        }
        
        //start travelfrom headA by nodeA or headB by nodeB such that
        //the remaining length from two node to tail are the same.
        ListNode* nodeA=headA;
        ListNode* nodeB=headB;
        while(m!=n) {
            if(n>m) {
                n--;
                nodeA=nodeA->next;
            } else {
                m--;
                nodeB=nodeB->next;                
            }
        }
        
        //nodeA and nodeB walking in the same time
        //and the first common point to meet is 
        //the answer.
        while(nodeA != nodeB) {
            nodeA=nodeA->next;
            nodeB=nodeB->next;
        }
        return nodeA;
        
    }
};