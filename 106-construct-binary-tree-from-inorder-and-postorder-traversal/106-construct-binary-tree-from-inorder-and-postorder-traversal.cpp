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
          TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int rootinx, int left, int right) {
        if (left > right) return NULL;
        int pivot = left; 
        while(inorder[pivot] != postorder[rootinx]) pivot++;
        
        rootinx--;
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->left = solve(postorder, inorder, rootinx-right+pivot, left, pivot-1);
        newNode->right = solve(postorder, inorder, rootinx, pivot+1, right);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
            int rootinx = n-1;
            return solve(postorder,inorder ,rootinx , 0 , n-1);
    }
};