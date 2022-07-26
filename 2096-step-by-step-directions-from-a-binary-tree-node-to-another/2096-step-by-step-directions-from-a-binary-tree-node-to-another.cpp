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
        TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
          
            if(root->val==p || root->val==q)
                return root;
            if(root->left==NULL && root->right==NULL)
                    return NULL;
            
            TreeNode *Left = NULL, *Right = NULL;
            if(root->left){
                   Left = lowestCommonAncestor(root->left,p,q);
            }
            if(root->right){
                   Right = lowestCommonAncestor(root->right,p,q);
            }
            if(Left && Right)
                    return root;
            
            return Left==NULL?Right:Left;
                    
    }
        bool path(TreeNode* root, int s, string& str){
                if(!root) return 0;
                if(root->val==s) return 1;
                str += 'L';
                auto res = path(root->left,s,str);
                if(res) return 1;
                str.pop_back();
                str += 'R';
                auto res1 = path(root->right,s,str);
                if(res1) return 1;
                str.pop_back();
                return 0;
                
        }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        root = lowestCommonAncestor(root,startValue,destValue);
            string p1 = "", p2 = "";
            path(root,startValue,p1);
            path(root,destValue,p2);
            for(int i = 0; i < p1.size(); i++)
                    p1[i] = 'U';
            
            p1 += p2;
            
            return p1;
    }
};