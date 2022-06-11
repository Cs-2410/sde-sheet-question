class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
            int m = nums[0];
            for(int i =0; i < nums.size(); ++i){
                    m = min(m , nums[i]);
                    if(nums[i] > m)
                            ans = max(ans , nums[i]-m);
            } 
            return ans;
    }
};