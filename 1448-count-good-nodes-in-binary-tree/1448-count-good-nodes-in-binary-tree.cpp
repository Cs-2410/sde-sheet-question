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
       void solve(TreeNode* root,int k , int& ans){
               if(root==NULL) return;
               if(root->val>=k){
                       k = root->val;
                       ans++;
               }
               solve(root->left,k,ans);
               solve(root->right,k,ans);
               return;
       } 
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
            int k = root->val;
            int ans = 0;
            solve(root,k,ans);
            return ans;
    }
};