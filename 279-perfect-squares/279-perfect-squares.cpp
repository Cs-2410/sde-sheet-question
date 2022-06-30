class Solution {
public:
        vector<int> dp;
        int func(int n){
                if(n==0) return 0;
                if(dp[n]!=-1) return dp[n];
                int ans=INT_MAX;
                for(int i=1;i*i<=n;i++)
                        ans=min(ans,1+func(n-i*i));
                dp[n]=ans;
                return ans;
        }
    int numSquares(int n) {
            dp.resize(n+1,-1);
           return func(n);
    }
};