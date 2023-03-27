class Solution {
public:
    string convert(string s, int numRows) {
        int m = s.size();
        if(numRows==1)
        return s;
        vector<vector<char>> mat(numRows,vector<char>(m,'0'));
        int flag = 0;
        int a=0,b=0;
        for(int i = 0; i<m; i++){
            if(flag==0){
                mat[a][b]=s[i];
                if(a==numRows-1){
                    a--;
                    b++;
                    flag=1;
                }
                else{
                   a++; 
                }
            }
            else {
                mat[a][b]=s[i];

                if(a==0){
                    flag=0;
                    a++;
                }
                else{
                    a--;
                    b++;
                }
            }
        }
        string ans = "";
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j]!='0'){
                  ans+=mat[i][j];
                }
            }
        }
        return ans;
    }
};