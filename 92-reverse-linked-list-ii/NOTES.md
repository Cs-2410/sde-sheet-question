ListNode* temp = new ListNode(0);
temp->next = head;
ListNode* curr = temp;
​
ListNode* left_prev = NULL;
int i = 0;
while(i<left){
left_prev = curr;
curr = curr->next;
i++;
}
ListNode* prev = left_prev;
ListNode* currn = curr;
int j = left;
while(j<=right){
ListNode* next = currn->next;
currn->next = prev;
prev = currn;
currn = next;
j++;
}
​
left_prev->next = prev;
curr->next = currn;
​
return temp->next;