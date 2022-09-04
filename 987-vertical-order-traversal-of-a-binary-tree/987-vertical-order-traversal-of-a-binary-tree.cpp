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
        void solve(TreeNode* root, priority_queue<pair< int, pair<int, int>>>& pq,int row,int col){
             if(root==NULL) return;
                
                     pq.push({-col,{-row,-root->val}});
             
                if(root->left){
                        solve(root->left,pq,row+1,col-1);
                }
                if(root->right){
                        solve(root->right,pq,row+1,col+1);
                }
                return ;
        }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        priority_queue<pair< int, pair<int, int>>> pq;
            vector<vector<int>> ans;
            if(!root) return ans;
            
            solve(root,pq,0,0);
            
            int c = -1001;
            vector<int> level;
            int flag = 0;
            while(!pq.empty()){
                    
               int x = -pq.top().first;
               int y = -pq.top().second.first;
               int z = -pq.top().second.second;
                    pq.pop();
                 if(c<x){
                         level.push_back(z);
                         c=x;
                         if(c==-pq.top().first) flag = 0;
                         else flag = 1;
                 }
                    else if(c==x){
                        level.push_back(z);
                            if(c==-pq.top().first) flag = 0;
                         else flag = 1;
                    }
                 if(flag){   
                 ans.push_back(level);
                 level.clear();
                 }      
            }
            if(level.size()>0) ans.push_back(level);
            return ans;
    }
};