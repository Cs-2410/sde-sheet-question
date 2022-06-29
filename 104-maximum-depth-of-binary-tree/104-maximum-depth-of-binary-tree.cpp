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
private:
     int solve(TreeNode* root){
             if(root == NULL)
                     return 0;
             int leftdep = 1, rightdep = 1;
             leftdep = solve(root->left) + 1;
             rightdep = solve(root->right) + 1;
             return max(leftdep , rightdep);
     }   
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
                return 0;
            int ans = solve(root);
            return ans;
    }
};