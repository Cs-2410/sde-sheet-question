class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       vector<int> ans;
            int startrow = 0;
            int startcol = 0;
            int lastrow = matrix.size()-1;
            int lastcol = matrix[0].size()-1;
            int count = 0;
            int total = matrix.size()*matrix[0].size();
            
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