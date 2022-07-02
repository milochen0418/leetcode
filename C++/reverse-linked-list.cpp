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
public:
    ListNode* reverseList(ListNode* head) {
        /*

     A    B    C
    nil   o -> o -> o -> o -> o -> o 

          A    B    C
    nil<- o    o -> o -> o -> o -> o 
          
          A    B    C
          o <- o    o -> o -> o -> o 
          
          
               A    B    C
          o <- o    o -> o -> o -> o 

               A    B    C
          o <- o <- o    o -> o -> o 
          

                    A    B    C
          o <- o <- o    o -> o -> o 

                    A    B    C
          o <- o <- o <- o    o -> o -> nil
          
                         A    B    C
          o <- o <- o <- o    o -> o -> nil
          
                         A    B    C
          o <- o <- o <- o <- o    o -> nil


                         A    B    C
          o <- o <- o <- o    o -> o -> nil
          
                              A    B    C
          o <- o <- o <- o <- o    o -> nil
          
                              A    B    C
          o <- o <- o <- o <- o <- o   nil
          
                                   A    B    C
          o <- o <- o <- o <- o <- o   nil

        */
        
        
        ListNode* A = nullptr;
        ListNode* B = head;
        ListNode* C = head?head->next:nullptr;
        while(B != nullptr) {
            B->next = A;
            A = B;
            B = C;
            if(C!=nullptr)C = C->next;
        }
        return A;
    }
};