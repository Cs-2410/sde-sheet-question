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
        vector<TreeNode*> ans;
         map<string , int> mp;
        string solve(TreeNode* root){
                if(root==NULL) return "";
                
                 string l = solve(root->left);
                 string r = solve(root->right);
                
                string s = "("+l+to_string(root->val)+r+")";
                if(mp[s]!=-1){
                       mp[s]++;        
                }
                if(mp[s]>1){
                        ans.push_back(root);
                        mp[s]=-1;      
                }
                
                return s;
        }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
            solve(root);
            
          return ans;  
    }
};