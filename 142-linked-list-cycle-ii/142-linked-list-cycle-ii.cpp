/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return 0;
            if(head->next==NULL) return 0;
            ListNode* fast = head, *slow = head;
            int cycle = 0;
            while(fast!=NULL && fast->next!=NULL){
                    fast=fast->next->next;
                    slow = slow->next;
                    
                    if(slow==fast){
                        cycle = 1;
                            break;
                    }
            }
            if(!cycle) return NULL;
            
            slow = head;
            
            while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
            }
            return fast;
    }
};