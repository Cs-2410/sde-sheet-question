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
        TreeNode* solve(vector<int>& preorder, vector<int>& postorder , int prelow, int prehigh , int postlow , int posthigh , map<int , int>& mp1 , map<int , int>& mp2){
                if(prelow > prehigh)
                return NULL;
                if(prelow == prehigh)
                 return new TreeNode(preorder[prelow]);
            TreeNode* node = new TreeNode();
            node->val = preorder[prelow];
                int i = mp2[preorder[prelow+1]];
                int j = mp1[postorder[posthigh-1]];
            
        node->left = solve(preorder , postorder , prelow + 1 , j-1 ,postlow ,i , mp1 ,mp2);
        node->right = solve(preorder, postorder , j , prehigh, i+1, posthigh-1 , mp1 ,mp2);
        return node;
        }
    
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
           int n = preorder.size();
            if(n == 1)
                 return new TreeNode(preorder[0]);
            map<int , int> mp1 , mp2;
            for(int i = 0; i < n; i++){
                    mp1[preorder[i]] = i;
                    mp2[postorder[i]] = i;
            }
            return solve(preorder , postorder , 0 , n-1 , 0 , n-1 , mp1 , mp2);
                
    }
};