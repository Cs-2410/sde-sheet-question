class Solution {
public:
        vector<int> dp;
        int solve(vector<int>& nums, int target, int sum){
           if(sum > target)
                   return 0;
                if(dp[sum]!=-1) return dp[sum];
              if(sum == target){
                      dp[sum]=1;
                return 1;
              }
                int count=0;
               for(int i = 0; i<nums.size(); i++){
                       
                        sum += nums[i];
                       count+=solve(nums , target ,sum);
                      
                       sum -= nums[i];
                }  
                dp[sum]=count;
                return count;
        }
        int combinationSum4(vector<int>& nums, int target) {
        int sum = 0;
                dp.resize(1003,-1);
            
            return solve(nums , target ,sum);
    }
};