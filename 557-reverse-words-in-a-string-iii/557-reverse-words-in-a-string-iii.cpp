class Solution {
public:
        void solve(string temp, string &ans){
               for(int i = temp.size()-1; i >= 0; i--){
                       ans += temp[i];
               }
        }
    string reverseWords(string s) {
        int n = s.size();
            string temp = "";
            string ans = "";
            for(int i = 0; i < n; i++){
                   if(i==n-1){
                           temp += s[i];
                           solve(temp,ans);
                   }
                    else if(s[i]==' '){
                            solve(temp,ans);
                            
                            ans += ' ';
                            temp = "";
                    }
                    else {
                            temp += s[i];
                    }
            }
            return ans;
    }
};