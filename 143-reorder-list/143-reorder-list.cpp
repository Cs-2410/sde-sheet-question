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
    void reorderList(ListNode* head) {
            if ((!head) || (!head->next) || (!head->next->next)) return;
            vector<int> arr;
            ListNode* temp = NULL;
            temp = head;
            while(temp){
              arr.push_back(temp->val);
                    temp = temp->next;
            }
          int n = arr.size()-1;
            ListNode* pptr = head;
            int i = 0, j = n;
            while(i < j){
                    pptr->val = arr[i];
                    pptr = pptr->next;
                    pptr->val = arr[j];
                    pptr = pptr->next;
                    i++;
                    j--;
            }
            if(i == j)
                    pptr->val = arr[i];
            
            
                    
            
    }
};