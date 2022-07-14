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
        TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& rootinx, int left, int right) {
        if (left > right) return NULL;
        int pivot = left; 
        while(inorder[pivot] != preorder[rootinx]) pivot++;
        
        rootinx++;
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->left = solve(preorder, inorder, rootinx, left, pivot-1);
        newNode->right = solve(preorder, inorder, rootinx, pivot+1, right);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
            int rootinx = 0;
            return solve(preorder,inorder ,rootinx , 0 , n-1);
    }
};