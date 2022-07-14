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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> stk;
            // vector<int> level;
            ListNode* temp = NULL;
            temp = head;
            int n = 0;
            while(temp){
                    // level[n] = 
                    n++;
                    temp = temp->next;
            }
            
            vector<int> ans(n,-1);
            ListNode* prev = NULL;
        ListNode* next = NULL;
            while(head){
                    next = head->next;
                    head->next = prev;
                    prev = head;
                    head = next;
            }
            head = prev;
            temp = head;
            int i = n-1;
            while(temp && i>=0){
                    while(!stk.empty() && stk.top()<=temp->val)
                            stk.pop();
                    if(stk.empty())
                            ans[i] = 0;
                    else
                            ans[i] = stk.top();
                    stk.push(temp->val);
                    temp = temp->next;
                    i--;
            }
            return ans;
    }
};