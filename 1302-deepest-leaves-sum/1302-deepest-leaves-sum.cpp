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
        void solve(TreeNode* root, int& globaldep ,int dep ,int& sum){
              if(!root)
                      return ;
                
                // cout<<sum<<" "<<globaldep<< " "<<dep<<endl;
                if(dep > globaldep){
                        globaldep = dep;
                        sum = 0;
                }
                if(dep == globaldep){
                        sum += root->val;
                }
                solve(root->left , globaldep, dep+1 ,sum);
                solve(root->right , globaldep, dep+1 ,sum);
                return ;
        }
    int deepestLeavesSum(TreeNode* root) {
        if(!root)
                return 0;
            int sum = 0;
            int globaldep = -1;
               solve(root , globaldep ,0 ,sum);
            return sum;
    }
};