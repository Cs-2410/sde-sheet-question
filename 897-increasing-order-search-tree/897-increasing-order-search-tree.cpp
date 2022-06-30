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
      TreeNode*  insert(vector<int>& ans , int i){
             if(i >= ans.size())
                     return NULL;
              TreeNode* nood = new TreeNode();
                if(i < ans.size()){
                        nood->val = ans[i];
                        nood->left = NULL;
                        nood->right = insert(ans , i + 1);
                }
                return nood;
        }
        
        
        void solve(TreeNode* root, vector<int>& ans) {
                if (root == NULL) 
            return ;
        solve(root->left, ans);
        ans.push_back(root->val);
        solve(root->right, ans);
                        
    }
        
      TreeNode* increasingBST(TreeNode* root) {
        vector<int> ans;
              if (root == NULL) 
            return root;
         solve(root , ans);
       return  insert(ans , 0);         
    }
};