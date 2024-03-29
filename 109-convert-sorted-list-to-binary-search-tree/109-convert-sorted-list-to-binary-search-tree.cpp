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
public:
        TreeNode* solve(vector<int>& nums , int l , int h){
        if(l > h)
                return NULL;
                if(l == h)
                 return new TreeNode(nums[l]);
            TreeNode* node = new TreeNode();
            int mid = l +((h-l)/2);
            node->val = nums[mid];
            node->left = solve(nums , l , mid-1);
            node->right = solve(nums , mid+1 , h);
            return node;
        }           
        TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 1)
                 return new TreeNode(nums[0]);
            TreeNode* node = new TreeNode();
            int l =0;
            int h =nums.size()-1;
            int mid = l +((h-l)/2);
            node->val = nums[mid];
            node->left = solve(nums , l , mid-1);
            node->right = solve(nums , mid+1 , h);
            return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
            vector<int> arr;
                ListNode* temp = NULL;
            temp = head;
            while(temp){
                    arr.push_back(temp->val);
                    temp = temp->next;
            }
            return sortedArrayToBST(arr);
    }
};