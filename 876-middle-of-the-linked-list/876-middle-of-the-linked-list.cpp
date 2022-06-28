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
    ListNode* middleNode(ListNode* head) {
        if(head == NULL)
                return 0;
            int count = 1;
        struct ListNode *temp =head;
        while(temp->next != NULL){
            count++;
            temp = temp->next;
        }
        count = count/2 + 1;
            int mid = 1;
             temp =head;
            while(mid < count){
                   temp = temp->next;
                    mid++;
            }
            return temp;
    }
};