class Solution {
public:
           int solve(vector<int> &nums){
      int n = nums.size();
     int perv1 = nums[0];
     int perv2 = 0;
   for(int i = 1; i < n; i++){
        int inc = perv2 + nums[i];
      int exc = perv1;
      int ans = max(inc , exc);
       perv2 = perv1;
       perv1 = ans;
   }
    return perv1;
}                  
        
         int rob(vector<int>& nums) {
            return solve(nums);
    }
};