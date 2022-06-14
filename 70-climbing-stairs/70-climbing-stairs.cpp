class Solution {
public:
    int climbStairs(int N) {
         if(N == 1 || N == 2)
    return N;

    long int dp[N+1];

    dp[0] = 1;
    dp[1] = 1;

    dp[2] = 2;

    for(int i=3;i<=N;i++)
    {
      dp[i] = dp[i-1] + dp[i-2];
    } 
    return dp[N];
    }
};