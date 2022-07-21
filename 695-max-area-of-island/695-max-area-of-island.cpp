class Solution {
public:  
        void dfs(vector<vector<int>>& image,int i, int j,int& temp){
                int n = image.size();
                int m = image[0].size();
                if(i<0 || j<0) return;
                if(i>=n || j>=m) return;
                if(image[i][j] != 1) return;
                
                temp++;
                image[i][j] = '0';
                
                dfs(image,i-1,j,temp);
                dfs(image,i+1,j,temp);
                dfs(image,i,j+1,temp);
                dfs(image,i,j-1,temp);
        }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
            int ans = INT_MIN;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int temp = 0;
                        dfs(grid, i, j,temp);
                        ans = max(ans,temp);
                }
            }
        }
            return (ans == INT_MIN)?0:ans;
    }
};