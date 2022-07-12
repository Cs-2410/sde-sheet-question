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
        ListNode* prev = NULL;
        ListNode* next = NULL;
            while(head){
                    next = head->next;
                    head->next = prev;
                    prev = head;
                    head = next;
            }
            head = prev;
            return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
            stack<int> stc1, stc2;
            ListNode* temp = NULL;
            temp = l1;
            while(temp){
                    stc1.push(temp->val);
                    temp = temp->next;
            }
            temp = l2;
            while(temp){
                    stc2.push(temp->val);
                    temp = temp->next;
            }
            int borrow = 0;
            ListNode ans(0);
            ListNode* ptr = &ans;
            while(!stc1.empty() || !stc2.empty() || borrow){
                   int sum = 0;
                   sum += borrow;
                    
                    if(!stc1.empty())
                   sum += stc1.top();
                    
                    if(!stc2.empty())
                   sum += stc2.top();
                   
                    borrow = sum/10;
                    
                    ptr->next = new ListNode(sum % 10);
                    ptr = ptr->next;
                    
                    if(!stc1.empty())
                    stc1.pop();
                    if(!stc2.empty())
                    stc2.pop();
            }
            return reverseList(ans.next);
    }
};