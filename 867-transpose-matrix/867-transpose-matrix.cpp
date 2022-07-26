class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
            vector<int> level;
            level.clear();
            for(int j = 0; j < matrix[0].size(); j++){
                    for(int i = 0; i < matrix.size(); i++){
                        level.push_back(matrix[i][j]);    
                    }
                    ans.push_back(level);
                    level.clear();
            }
            return ans;
    }
};