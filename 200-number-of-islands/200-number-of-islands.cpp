class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, island = 0,offsets[] = {0, 1, 0, -1, 0};
            
            for(int i = 0; i < m; i++){
                    for(int j =0; j < n; j++){
                            if(grid[i][j]=='1'){
                                    island++;
                                    queue<pair<int ,int>> q;
                                    q.push({i,j});
                                    grid[i][j]='0';
                                    while(!q.empty()){
                                            int row = q.front().first;
                                            int col = q.front().second;
                                            q.pop();
                                           for (int k = 0; k < 4; k++) {
                            int r = row + offsets[k], c = col + offsets[k + 1];
                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                                grid[r][c] = '0';
                                q.push({r, c});
                            }
                        }
                                            
                                    }
                            }
                    }
            }
            return island;
    }
};