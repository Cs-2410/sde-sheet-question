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
        TreeNode* solve(vector<int>& nums, int start , int end){
                if(start > end) return NULL;
                TreeNode* node = new TreeNode();
                if(start == end){
                        node->val = nums[start];
                        return node;
                }
                int  pos;
                int value = INT_MIN;
                 for(int i = start; i <= end; i++){
                    value = max(value,nums[i]);
                         if(value == nums[i]) pos = i;
                 }                
                 node->val = value;
                 node->left = solve(nums , start, pos-1);
                 node->right = solve(nums, pos+1, end);
                return node;
        }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = new TreeNode;
            int n = nums.size();
            return solve(nums , 0 , n-1);
    }
};