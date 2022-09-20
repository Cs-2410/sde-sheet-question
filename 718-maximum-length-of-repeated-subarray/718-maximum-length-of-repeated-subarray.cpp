class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
            int m = nums2.size();
            
            vector<int> dp(m+1);
            int ans = INT_MIN;
            
            for(int i = 1; i <=n; i++){
                    for(int j = m; j >0; j--){
                            if(nums1[i-1]==nums2[j-1]){
                                    dp[j]=1+dp[j-1];
                            }
                            else
                                    dp[j]=0;
                            
                            ans = max(ans,dp[j]);
                    }
            }
            return ans;
    }
};