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
    int ans;
        void func(TreeNode* root,int depth){
                if(root==NULL) return;
                if(root->left==NULL && root->right==NULL){
                        ans=min(ans,depth);
                        return;
                }
                func(root->left,depth+1);
                func(root->right,depth+1);
        }
    int minDepth(TreeNode* root) {
        ans=INT_MAX;
         if(root == NULL)
                return 0;
        func(root,1);
        return ans;   
    }
};