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
    ListNode* partition(ListNode* head, int x) {
        
            ListNode *head1=NULL,*head2=NULL,*temp1=NULL,*temp2=NULL,*temp=head;
            while(temp!=NULL){
                    if(temp->val<x){
                            ListNode* newNode = new ListNode(temp->val);
                            if(head1==NULL){
                                    head1=newNode;
                                    temp1=newNode;
                            }
                            else{
                                    temp1->next=newNode;
                                    temp1=newNode;
                            }
                    }
                    else{
                           ListNode* newNode = new ListNode(temp->val);
                           if(head2==NULL){
                                    head2=newNode;
                                    temp2=newNode;
                            }
                            else{
                                    temp2->next=newNode;
                                    temp2=newNode;
                            } 
                    }
                    temp=temp->next;
            }
            if(head1==NULL) return head2;
            temp1->next=head2;
            return head1;
    }
};