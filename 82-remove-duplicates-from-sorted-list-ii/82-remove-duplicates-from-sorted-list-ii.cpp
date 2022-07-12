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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
            map<int , int> mp;
            ListNode* temp = NULL;
            temp = head;
            while(temp){
                    mp[temp->val]++;
                    temp = temp->next;
            }
            ListNode ans(0) , *p = &ans;
            for(auto ele : mp){
                    if(ele.second == 1){
                            p->next = new ListNode(ele.first);
                    p = p->next;
                    }
            }
            return ans.next;
    }
};