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
         vector<vector<int>> ans;
        vector<int> level;
        void solve(TreeNode* root, int targetSum){
                
                if(!root)
                        return ;
                level.push_back(root->val);
                targetSum -= root->val;
                if((targetSum == 0)&&(root->left == NULL)&&(root->right == NULL)){
                        ans.push_back(level);
                        
                }
                    
                   solve(root->left ,targetSum);
                   solve(root->right ,targetSum);
                 level.pop_back();
        }
        vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)
                return ans;
                
           solve(root ,targetSum);
                return ans;
    }
};