class Solution {
public:
        int solve(vector<int>& prices, int fee,int idx, bool buy,vector<vector<int>>& dp){
            if(idx==prices.size())
                    return 0;
                if(dp[idx][buy] != -1) return dp[idx][buy];
                int ans1 = solve(prices,fee,idx+1,buy,dp);
                int ans2 = 0;
                if(buy)
                  ans2 = -prices[idx]+solve(prices,fee,idx+1,0,dp);
                else
                  ans2 = prices[idx]-fee+solve(prices,fee,idx+1,1,dp);
                dp[idx][buy] = max(ans1,ans2);
                return dp[idx][buy];
        }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
            vector<vector<int>> dp(n,vector<int>(2,-1));
            return solve(prices,fee,0,1,dp);
    }
};