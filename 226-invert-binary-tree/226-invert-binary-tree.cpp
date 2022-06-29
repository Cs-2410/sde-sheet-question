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
// class Solution {
// public:
//         TreeNode* solve(TreeNode* root){
//         TreeNode* ans;
//                 while((root->left != NULL) && (root->right != NULL)){
//                    auto temp=root->left;
//                    root->left=root->right;
//                         root->right=temp;
                        
//                 }
//               return ans;  
//         }
//         TreeNode* invertTree(TreeNode* root) {
//         if(root == NULL)
//                 return NULL;
//           TreeNode* node = solve(root);
//             return node;
//     }
// };
class Solution {
public:
        TreeNode* invertTree(TreeNode* root){
                if(root==NULL) return root;
                  auto temp=root->left;
                   root->left=root->right;
                        root->right=temp;
                invertTree(root->left);
                invertTree(root->right);
                return root;
    }
};