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
    vector<double> averageOfLevels(TreeNode* root) {
        
            queue<TreeNode*> q;
            vector<double> ans;
            if(root==NULL) return ans;
            
            q.push(root);
            
            while(!q.empty()){
                   double sum=0;
                    int count=0;
                    queue<TreeNode*> temp;
                    while(!q.empty()){
                            TreeNode* node = q.front();
                            q.pop();
                            sum += node->val;
                            count++;
                            if(node->left)
                                    temp.push(node->left);
                          if(node->right)
                                    temp.push(node->right);  
                    }
                    q = temp;
                    ans.push_back(sum/count);
            }
            return ans;
    }
};