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
        void solve(TreeNode* root, queue<TreeNode*>& q){
                if(root==NULL) return ;
                
                q.push(root);
                solve(root->left,q);
                solve(root->right,q);
                return ;
        }
    void flatten(TreeNode* root) {
        if(!root) return;
            
            queue<TreeNode*> q;
            solve(root,q);
            
            TreeNode* node = root;
            TreeNode* prev = NULL;
            while(!q.empty()){
                    node = q.front();
                    node->left = NULL;
                   if(prev) 
                    prev->right = node;
                    q.pop();
                    prev = node;
            }
            return;
    }
};