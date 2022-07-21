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
    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode* temp = head;
            vector<int> ans;
            ListNode* node = temp;
            while(node){
                    
                    ans.push_back(node->val);
                    node = node->next;
                                  if(ans.size() == k){
                                          reverse(ans.begin(),ans.end());
                                          int j = 0;
                                          while(j < ans.size()){
                                                  temp->val = ans[j];
                                                  temp = temp->next;
                                                  j++;
                                          }
                                          ans.clear();
                                  }
            }
                    return head;
    }
};