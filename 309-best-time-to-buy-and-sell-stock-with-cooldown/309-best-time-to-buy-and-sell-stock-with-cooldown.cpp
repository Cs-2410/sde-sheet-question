class Solution {
public:
        int solve(vector<int>& prices,int idx,bool buy,vector<vector<int>>& dp){
                if(idx >= prices.size())
                        return 0;
                if(dp[idx][buy] != -1) return dp[idx][buy];
                int nothing = solve(prices,idx+1,buy,dp);
                int ans = 0;
                if(buy)
                 ans =-prices[idx]+solve(prices,idx+1,0,dp);
                else
                ans = prices[idx]+solve(prices,idx+2,1,dp);
                dp[idx][buy] = max(nothing,ans);
               return dp[idx][buy]; 
        }
    int maxProfit(vector<int>& prices) {
            int n = prices.size();
            vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(prices,0,1,dp);
    }
};