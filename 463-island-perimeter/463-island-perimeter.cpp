class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int totper = 0,red = 0;
            for(int i = 0; i < grid.size(); i++){
                for(int j = 0; j < grid[0].size(); j++){
                        if(grid[i][j] == 1){
                           totper++;
                            if(i!=0 && grid[i-1][j] == 1) red++;
                        if(j!=0 && grid[i][j-1] == 1) red++;
                        }
                }
        }
            return 4*totper-red*2;
    }
};