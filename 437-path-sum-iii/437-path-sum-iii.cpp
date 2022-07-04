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
        int count;
        void func2(TreeNode* root, long long int sum,int targetSum){
                if(!root) return;
                if(sum+root->val==targetSum) count++;
                func2(root->left,sum+root->val,targetSum);
                func2(root->right,sum+root->val,targetSum);
        }
        void func1(TreeNode* root, int targetSum){
                if(root==NULL) return;
                func2(root,0,targetSum);
                func1(root->left,targetSum);
                func1(root->right,targetSum);
        }
    int pathSum(TreeNode* root, int targetSum) {
        
            count=0;
            func1(root,targetSum);
            return count;
           
    }
};