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
        bool ans = false;
        void solve(TreeNode* root, int targetSum){
                if(!root)
                        return ;
                targetSum -= root->val;
                if((targetSum == 0)&&(root->left == NULL)&&(root->right == NULL)){
                        ans = true;
                        return;
                }
                solve(root->left , targetSum);
                solve(root->right , targetSum);
                
        }
        bool hasPathSum(TreeNode* root, int targetSum) {
        solve(root , targetSum);
                return ans;
    }
};