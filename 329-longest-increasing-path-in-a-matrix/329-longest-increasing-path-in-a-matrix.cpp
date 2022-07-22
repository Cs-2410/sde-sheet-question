class Solution {
public:

        int dfs(vector<vector<int>>& image,int i, int j,int temp,vector<vector<int>>& dp){
                int n = image.size();
                int m = image[0].size();
                if(i<0 || j<0) return 0;
                if(i>=n || j>=m) return 0;
                if(image[i][j] <= temp) return 0;
                
                
                if(dp[i][j] != 0) return dp[i][j];
                
                temp = image[i][j];
                
                int a =dfs(image,i-1,j,temp,dp);
                int b =dfs(image,i+1,j,temp,dp);
                int c =dfs(image,i,j+1,temp,dp);
                int d =dfs(image,i,j-1,temp,dp);
                dp[i][j] = max(dp[i][j],max(a,max(b,max(c,d))))+1;
                return dp[i][j];
        }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
            int island = 0;
            for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                  int temp = -1;
                   
                    
                   island = max(island,dfs(matrix, i, j,temp,dp));
            }
        }
        return island;
    }
};