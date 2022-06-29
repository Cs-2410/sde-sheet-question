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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stc;
        vector<int> result;
        //base case
        if(root==NULL)
        return result;
        stc.push(root);
    while(!stc.empty())
    {
        TreeNode* node= stc.top();  
        result.push_back(node->val);
        stc.pop();
        if(node->left)
        stc.push(node->left);
        if(node->right)
        stc.push(node->right);
    }
     reverse(result.begin(),result.end());
     return result;
    }
};