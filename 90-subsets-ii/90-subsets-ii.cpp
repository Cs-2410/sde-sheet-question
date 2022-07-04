class Solution {
public:
        vector<vector<int>> ans;
        vector<int> level;
        void solve(vector<int>& nums ,int index){
                        ans.push_back(level);
                for(int i = index ; i < nums.size(); i++){
                        if((i > index)&&(nums[i] == nums[i-1])) continue;
                      level.push_back(nums[i]);
                      solve(nums , i+1);
                        level.pop_back();      
              }  
        }
                
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
          sort(nums.begin() , nums.end());
            solve(nums ,0);
            return ans;
            
    }
};