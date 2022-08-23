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
    int pairSum(ListNode* head) {
        int count = 0; 
    ListNode* current = head;
    while (current != NULL) 
    { 
        count++; 
        current = current->next; 
    }
            vector<int> ans;
            ListNode* temp = head;
            
            while(temp != NULL){
                    ans.push_back(temp->val);
                    temp = temp->next;
            }
          int k = 0;
            int sum = 0;
            while(k<(count/2)){
                int level = ans[k]+ans[count-1-k];    
                sum = max(sum,level);
                    k++;
            }
            return sum;
    }
};