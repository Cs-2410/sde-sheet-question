class Solution {
public:
        vector<vector<int>> ans;
        vector<int> level;
        map<vector<int>, int> mp;
        void solve(vector<int>& candidates, int target, int index, int sum){
           if(sum > target)
                   return ;
                
              if(sum == target)
              {  if(mp.find(level) == mp.end()){
                      ans.push_back(level);
                    mp[level] = 1;
              }
               
                return ;
              }
              for(int i=index; i<candidates.size();i++){
                      
                      if(i>index && candidates[i]==candidates[i-1]) continue;
                        level.push_back(candidates[i]);
                        sum += candidates[i];
                       solve(candidates , target ,i+1 ,sum);
                       level.pop_back();
                       sum -= candidates[i];
                }
        }
                       
        
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int sum = 0;
            if(target == 0)
                    return ans;
            sort(candidates.begin() , candidates.end());
            solve(candidates , target ,0 ,sum);
            return ans;
    }
};