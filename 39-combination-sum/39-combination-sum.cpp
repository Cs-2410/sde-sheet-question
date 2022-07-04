class Solution {
public:
      vector<vector<int>> ans;
        vector<int> level;
        void solve(vector<int>& candidates, int target, int ind, int sum){
           if(sum > target)
                   return ;
                
              if(sum == target)
              {  ans.push_back(level);
                return ;
              }
               for(int i = ind; i<candidates.size(); i++){
                        level.push_back(candidates[i]);
                        sum += candidates[i];
                       solve(candidates , target ,i ,sum);
                       level.pop_back();
                       sum -= candidates[i];
                }
                
                
                
                
        }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            int sum = 0;
            if(target == 0)
                    return ans;
            
            solve(candidates , target ,0 ,sum);
            return ans;
    }
};