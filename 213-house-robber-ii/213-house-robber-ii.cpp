class Solution {
public:
               int solve(vector<int> num){
      int n = num.size();
     int perv1 = num[0];
     int perv2 = 0;
   for(int i = 1; i < n; i++){
      int ans = max(perv2 + num[i] , perv1);
       perv2 = perv1;
       perv1 = ans;
   }
    return perv1;
}                  
        
         int rob(vector<int>& nums) {
        int n = nums.size();
                 if(n == 1)
                         return nums[0];
            vector<int> first , last;
            for(int i = 0; i < n; i++){
                    if(i != n-1)
                            first.push_back(nums[i]);
                    if(i != 0)
                            last.push_back(nums[i]);
            }
            return max(solve(first) , solve(last));
    }
};