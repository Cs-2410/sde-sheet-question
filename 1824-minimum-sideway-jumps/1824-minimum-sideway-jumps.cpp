class Solution {
public:
        int solve(vector<int>& obstacles,int curlane,int pos,vector<vector<int>>& dp){
                if(pos == obstacles.size()-1)
                        return 0;
                if(dp[curlane][pos] != -1) return dp[curlane][pos];
                if(obstacles[pos+1] != curlane)
                        return solve(obstacles,curlane,pos+1,dp);
                else{
                        int ans = INT_MAX;
                        for(int i = 1; i <= 3; i++){
                                if(curlane != i && obstacles[pos] != i){
                                        ans = min(ans , 1+solve(obstacles,i,pos,dp));
                                }
                                        
                        }
                       dp[curlane][pos] = ans; 
                        return ans;
                }
               
        }
    int minSideJumps(vector<int>& obstacles) {
            
            int n = obstacles.size();
            vector<vector<int>> dp(4,vector<int>(n,-1));
            return solve(obstacles,2,0,dp);
    }
};