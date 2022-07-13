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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode* > q;
            vector<vector<int>> result; 
            vector<int> level;
            if(root == NULL)
                    return result;
            q.push(root);
            
            while(!q.empty()){
                    int i, n = q.size();
                    for(i = 0; i < n; i++){
                            TreeNode* p = q.front();
                            q.pop();
                            level.push_back(p->val);
                            if(p->left != NULL){
                                    q.push(p->left);
                            }
                            if(p->right != NULL){
                                    q.push(p->right);
                            }
                    }
                            result.push_back(level);
                            level.clear();
                  
            }
          reverse(result.begin() , result.end());
            return result;
    }
};