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
        int solve(TreeNode* root , int& ans){
                if(root == NULL)
                        return 0;
                int leftsubtree = solve(root->left , ans);
                int rightsubtree = solve(root->right , ans);
                ans = max(ans,abs(leftsubtree-rightsubtree));
                return (max(leftsubtree , rightsubtree) +1);
                
        }
        bool isBalanced(TreeNode* root) {
        if(root == NULL)
                return true;
       int ans = 0;
                solve(root , ans);
        if(ans > 1)
                return false;
                else 
                return true;
    }
};