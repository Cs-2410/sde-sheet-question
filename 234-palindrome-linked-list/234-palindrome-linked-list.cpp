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
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         int stack_arr[];
//         int first = -1;
//         ListNode* temp = head;
//             while(temp->next != NULL){
//                     int i;
//                     first += 1;
//                     for(i = first; i > 0; i--)
//                             stack_arr[i] = stack_arr[i-1];
//                     stack_arr[0] = temp->value;
//                     temp = temp->next;
//             }
//             temp = head;
//             while(temp->next != NULL){
//                     int i , value;
//                 value = stack_arr[0];
//                 for(i = 0; i < first ; i++)
//                             stack_arr[i] = stack_arr[i-1];
//                 first -= 1;
//                     if(temp-> == value)
//                             temp = temp->next;
//                       else
//                               return false;
//             }
//             return true;
//     }
// };
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        stack<int> stk;
        while(temp){
            stk.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp){
                int val=stk.top();
                if(temp->val!=val) return false;
                temp=temp->next;
                stk.pop();
        }
        return true;
    }
};