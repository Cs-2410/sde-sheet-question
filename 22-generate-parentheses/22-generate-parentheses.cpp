class Solution {
public:vector<string> ans;
        
       void solve(int n ,int m , string temp = ""){
            if((n == 0)&&(m == 0)){
                    ans.push_back(temp);
                   
                    return ;
            }
               
               if(m>0){
                       
                       solve(n ,m-1,temp+")");
               }
               if(n>0){
                     
                     solve(n-1, m+1, temp+"(");  
               }
               
               
       }
        vector<string> generateParenthesis(int n) {
                
                solve(n , 0, "");
            return ans;
    }
};