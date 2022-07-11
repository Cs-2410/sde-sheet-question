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
    ListNode* insertionSortList(ListNode* head) {
        priority_queue<int> pq;
            ListNode* temp = NULL;
            temp = head;
            while(temp){
                    pq.push(-temp->val);
                    temp = temp->next;
            }
            ListNode ans(0);
            ListNode* ptr = &ans;
          while(!pq.empty()){
             ptr->next = new ListNode(-pq.top());
                  ptr = ptr->next;
                  pq.pop();
          } 
            return ans.next;
    }
};