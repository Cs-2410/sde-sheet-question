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
    vector<int> rightSideView(TreeNode* root) {
         queue<pair<TreeNode* ,int>> q;
            map<int , int> mp; 
            vector<int> ans;
            if(root == NULL)
                    return ans;
            q.push({root , 0});
            
            
            while(!q.empty()){
                    int i, n = q.size();
                    for(i = 0; i < n; i++){
                            TreeNode* p = q.front().first;
                            int sum =q.front().second;
                            q.pop();
                             
                            if(mp[sum]==0){
                             mp[sum] = p->val;
                             ans.push_back(p->val);
                            }
                            if(p->right != NULL){
                                    q.push({p->right , sum+1});
                            }
                            if(p->left != NULL){
                                    q.push({p->left , sum+1});
                                    
                            }
                            
                                    
                            
                    }
                            
                  
            }
            return ans;
                
    }
};