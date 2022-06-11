class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       vector<int> ans;
            int row = matrix.size();
            int col = matrix[0].size();
            int startrow = 0;
            int startcol = 0;
            int lastrow = row-1;
            int lastcol = col-1;
            int count = 0;
            int total = row*col;
            
           while(count < total){
                   for(int index = startcol; count < total && index <= lastcol; index++){
                           ans.push_back(matrix[startrow][index]);
                           count++;
                   }
                   startrow++;
                   for(int index = startrow; count < total && index <= lastrow; index++){
                           ans.push_back(matrix[index][lastcol]);
                           count++;
                   }
                   lastcol--;
                     for(int index = lastcol; count < total && index >= startcol; index--){
                           ans.push_back(matrix[lastrow][index]);
                           count++;
                   }
                   lastrow--;
                      for(int index = lastrow; count < total && index >= startrow; index--){
                           ans.push_back(matrix[index][startcol]);
                           count++;
                   }
                   startcol++;
             }
            return ans;
    }      
};