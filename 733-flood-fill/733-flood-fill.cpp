class Solution {
public:
        void dfs(int i, int j, int i_color, int color, vector<vector<int>>& image){
                int n = image.size();
                int m = image[0].size();
                if(i<0 || j<0) return;
                if(i>=n || j>=m) return;
                if(i_color != image[i][j]) return;
                
                image[i][j] = color;
                
                dfs(i-1,j,i_color,color,image);
                dfs(i+1,j,i_color,color,image);
                dfs(i,j+1,i_color,color,image);
                dfs(i,j-1,i_color,color,image);
        }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int i_color = image[sr][sc];
            if(i_color != color)
                    dfs(sr,sc,i_color,color,image);
            return image;
    }
};