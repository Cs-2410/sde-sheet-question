class Solution {
public:
    int solve(vector<int> coins, int tar, int m, vector<int> &dp) {
        if(tar == 0)
            return 0;
        if(tar < 0)
            return INT_MAX;
        
        if(dp[tar] != -1) return dp[tar];
        int res = INT_MAX;
        for(int i = 0; i < m; i++) {
            if(coins[i] <= tar) {
                int ans = solve(coins, tar-coins[i], m, dp);
                if(ans != INT_MAX)
                    res = min(res, 1 + ans);
            }
        }
        return dp[tar] = res;
    }
        
        
      int coinChange(vector<int>& coins, int n) {
        int M = coins.size();
        vector<int> dp(n+1, -1);
        int ans = solve(coins, n, M, dp);
        return ans==INT_MAX?-1:ans;
    }
};