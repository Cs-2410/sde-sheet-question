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
    TreeNode* solve(TreeNode* node,vector<int>& nums, int l,int h){
            if(l>h) return NULL;
            if(l==h){
               TreeNode* root = new TreeNode();
               root->val = nums[l];
               return root;
            }
          int mid = l + (h-l)/2 ;
          TreeNode* root = new TreeNode();
            root->val = nums[mid];
            root->left = solve(node,nums,l,mid-1);
            root->right = solve(node,nums,mid+1,h);
            return root;
    }   
      
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0, h = nums.size()-1;
            int mid = l + (h-l)/2 ;
            TreeNode* node = new TreeNode();
            node->val = nums[mid];
            node->left = solve(node,nums,l,mid-1);
            node->right = solve(node,nums,mid+1,h);
            return node;
    }
};