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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public: ListNode *level = NULL;
        bool isSubPath2(ListNode* head, TreeNode* root){
        ListNode *temp = head;
            if(temp==NULL) return true;
            if(root==NULL) return false;
            // cout<<temp->val<<"**"<<root->val<<endl;
            if(temp->val==root->val){
                 if(isSubPath2(temp->next,root->left)) return true;
                 if(isSubPath2(temp->next,root->right)) return true;
                    
            }
            
                 //    if(isSubPath2(level,root->left)) return true;
                 // if(isSubPath2(level,root->right)) return true;
           
          return false;
}
    bool isSubPath(ListNode* head, TreeNode* root) {
          level = head;
            if(!root) return false;
            
            if(isSubPath2(head,root)) return true;
          
            return isSubPath(head,root->left) || isSubPath(head,root->right);  
    }
};