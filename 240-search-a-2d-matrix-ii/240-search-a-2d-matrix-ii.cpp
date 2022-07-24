class Solution {
public:
      bool find(vector<vector<int>>& matrix,int idx,int low,int end,int target){
              if(low > end) return false;
              
              int mid = low + (end-low)/2;
              // cout<<matrix[idx][mid]<<endl;
              if(matrix[idx][mid]==target) return true;
              
              else if(matrix[idx][mid] < target){
                  if(find(matrix,idx,mid+1,end,target)) return true;
              }
              else if(matrix[idx][mid] > target){
                  if(find(matrix,idx,low,mid-1,target)) return true;
              }
              
              return false;
      }  
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++){
              if(find(matrix,i,0,matrix[0].size()-1,target)) return true;
        }
            return false;
    }
};