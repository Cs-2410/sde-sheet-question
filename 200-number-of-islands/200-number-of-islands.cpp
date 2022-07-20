class Solution {
public:
        
        void dfs(vector<vector<char>>& image,int i, int j){
                int n = image.size();
                int m = image[0].size();
                if(i<0 || j<0) return;
                if(i>=n || j>=m) return;
                if(image[i][j] != '1') return;
                
                image[i][j] = '0';
                
                dfs(image,i-1,j);
                dfs(image,i+1,j);
                dfs(image,i,j+1);
                dfs(image,i,j-1);
        }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return islands;
    }
};