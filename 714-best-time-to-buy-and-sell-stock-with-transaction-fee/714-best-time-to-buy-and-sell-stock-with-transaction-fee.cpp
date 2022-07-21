class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
            vector<vector<int>> dp(n+1,vector<int>(2,0));
            for(int idx = n-1; idx >= 0; idx--){
                    dp[idx][1] = max(dp[idx+1][1],-prices[idx]+dp[idx+1][0]);
                    dp[idx][0] = max(dp[idx+1][0],-fee+prices[idx]+dp[idx+1][1]);
            }
           return dp[0][1]; 
    }
};