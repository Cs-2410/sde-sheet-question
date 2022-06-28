class Solution {
public:
    int maxDepth(string s) {
        stack<char> stc;
            int count = 0;
            int ans = 0;
            for(int i = 0; i < s.size(); i++){
                    if(s[i] == '('){
                            stc.push(s[i]);
                            count++;
                            ans = max(ans , count);
                    }
                    else {
                            if(s[i] == ')' && stc.top() == '('){
                            stc.pop();
                            count--;
                            }
                         }
            }
            return ans;
                    
     }
};