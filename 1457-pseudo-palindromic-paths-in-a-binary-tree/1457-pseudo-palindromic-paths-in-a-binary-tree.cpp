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
        int count=0;
    void dfs(TreeNode* root,int bitVec)
    {
        if(!root)
            return;
        if(!root->left&&!root->right)			
        {
            count+=__builtin_popcount(bitVec^(1<<root->val))<=1;
            return;
        }
        dfs(root->left,bitVec^(1<<root->val)),dfs(root->right,bitVec^(1<<root->val));	
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root,0);
        return count;
    }
};