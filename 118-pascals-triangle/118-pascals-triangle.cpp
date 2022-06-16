class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r(numRows);
            for(int i=0; i<numRows; i++){
                    r[i].resize(i+1);
                    for (int j=0; j<=i; j++)
                            if(j==0||j==i)
                                        r[i][0] = r[i][i] =1;
                                  
                    else
                            r[i][j] = r[i-1][j-1] + r[i-1][j];
            }
             return r;      
    }
};