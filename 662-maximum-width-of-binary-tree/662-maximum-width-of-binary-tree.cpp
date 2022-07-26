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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
            queue<pair<TreeNode*,unsigned long long>> q;
            q.push({root,1});
            unsigned long long width = 0;
            while(!q.empty()){
                    
                          unsigned long long l = q.front().second;
                    unsigned long long len = l;
                    unsigned long long n = q.size();
                    for(int i = 0; i < n; i++){
                             len = q.front().second;
                            TreeNode* node = q.front().first;
                            q.pop();
                            if(node->left) q.push({node->left,len*2});
                            if(node->right) q.push({node->right,len*2 + 1});
                    }
                   width = max(width,len+1-l); 
            }
            return width;
    }
};