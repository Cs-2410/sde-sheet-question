/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
//         unordered_map<int> mp;
//         ListNode *temp = head;
//             int flag = 0;
//             while(temp->next != NULL){
//                     if(mp.find(temp) != mp.end()){
//                             mp.insert[temp];
//                             temp = temp->next;
//                     }
//                     else{
//                             flag = 1;
//                            break;
//                     } 
//             }
//             if flag = 1;
//             return true;
            
//             else
//                     return false;
//     }
           ListNode *fast=head, *slow=head;
        while(fast!=NULL && fast->next!=NULL){
                fast=fast->next->next;
                slow=slow->next;
                if(slow == fast)
                        return true;
        }
            return false;
    }      
};