class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
            int n = mat[0].size();
            int row = m-1;
            int col = 0;
            int flag = 0;
            priority_queue<int> pq;
            while(row>=0 && col < n){
                    if(row==0) flag = 1;
                    int frow = row;
                    int fcol = col;
                 while(frow<m && fcol<n){
                         pq.push(mat[frow][fcol]);
                         frow++;
                         fcol++;
                 }
                    int srow = frow-1;
                    int scol = fcol-1;
                    while(srow>=0 && scol>=0){
                            mat[srow][scol]=pq.top();
                            srow--;
                            scol--;
                            pq.pop();
                    }
                    if(!flag)row--;
                    else if(flag)col++;
                    
            }
        return mat;    
    }
};