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
   int tot = 0;
        int mod = 1e9+7;
        public:
        int sum_subtree(TreeNode* root){
                if(root==NULL) return 0;
                if(root->left==NULL && root->right==NULL)
                        return root->val;
                int left = sum_subtree(root->left);
                int right = sum_subtree(root->right);
                
                root->val+=left+right;
                return root->val;
        }
        void splittree(TreeNode* root,long long& ans){
                if(root==NULL) return;
                
                if(root->left){
                        long long sum1 = root->left->val;
                        long long sum2 = tot-sum1;
                        ans = max(ans,sum1*sum2);
                }
                
                if(root->right){
                        long long sum1 = root->right->val;
                        long long sum2 = tot-sum1;
                        ans = max(ans,sum1*sum2);
                }
                
                splittree(root->left,ans);
                splittree(root->right,ans);
        }
    int maxProduct(TreeNode* root) {
        tot = sum_subtree(root);
            
            long long ans = 0;
            splittree(root,ans);
            
            return ans%mod; 
    }
};