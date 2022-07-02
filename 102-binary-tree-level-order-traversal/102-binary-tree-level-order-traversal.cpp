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
//     vector<vector<int>> levelOrder(TreeNode* root) {
//           queue<TreeNode* > q;
//             vector<vector<int>> result; 
//             vector<int> level;
//             if(root == NULL){
//                     q.push(root);
//                     level.push_back(root->val);
//                     result.push_back(level);
//                     level.clear();
//             }
//             while(!q.empty()){
//                     int i, n = q.size();
//                     for(i = 0; i < n; i++){
//                             TreeNode* p = q.front();
//                             q.pop();
//                             if(p->left != NULL){
//                                     q.push(p->left);
//                                     level.push_back(p->left->val);
//                             }
//                             if(p->right != NULL){
//                                     q.push(p->right);
//                                     level.push_back(p->right->val);
//                             }
//             }
//                     if(!level.empty() && i == n){
//                             result.push_back(level);
//                             level.clear();
//                     }
//             }
//           return result;        
//     }
// };
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
          queue<pair<TreeNode*,int> > q;
            vector<vector<int>> result; 
            vector<int> level;
            q.push({root,0});
            int index=0;
            while(!q.empty()){
                    auto ele=q.front();
                    q.pop();
                    if(ele.second>index){
                            index=ele.second;
                            result.push_back(level);
                            level.clear();
                    }
                    if(ele.first==NULL) continue;
                    level.push_back(ele.first->val);
                    q.push({ele.first->left,ele.second+1});
                    q.push({ele.first->right,ele.second+1});
            }
          return result;        
    }
};