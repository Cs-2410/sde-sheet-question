class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
            int n=matrix.size(),m=matrix[0].size(),count=0;
            vector<int> t(m,0);
            vector<vector<int>> up(n,t);
            vector<vector<int>> left(n,t);
            vector<vector<int>> ans(n,t);
            for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                            if(matrix[i][j]==0)
                            {
                                    left[i][j]=0;
                                    up[i][j]=0;
                                    ans[i][j]=0;
                            }
                            else{
                                    left[i][j]=(j>0)?(left[i][j-1]+1):1;
                                    up[i][j]=(i>0)?(up[i-1][j]+1):1;
                            }
                            if(i==0 || j==0) ans[i][j]=matrix[i][j];
                            else ans[i][j]=min(ans[i-1][j-1]+1,min(left[i][j],up[i][j]));
                            count+=ans[i][j];
                    }
            }
            return count;
    }
};