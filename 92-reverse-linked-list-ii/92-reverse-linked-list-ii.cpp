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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* leftn = head;
            for(int i = 1; i < left; i++)
                    leftn = leftn->next;
            ListNode* node = leftn;
            vector<int> ans;
            for(int j = 0; j < right-left+1; j++){
                    ans.push_back(node->val);
                    node = node->next;
            }
            reverse(ans.begin() , ans.end());
            
            for(int i = 0; i < ans.size(); i++){
                    leftn->val = ans[i];
                    leftn = leftn->next;
            }
            return head;
    }
};