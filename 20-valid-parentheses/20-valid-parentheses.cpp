class Solution {
public:
    bool isValid(string s) {
        stack<char> stc;
            for(int i = 0; i < s.size(); i++){
                    if(s[i] == '(' || s[i] == '{' || s[i] =='[')
                            stc.push(s[i]);
                    else {
                            if(stc.empty())
                                    return false;
                           else if(s[i] == ')' && stc.top() == '(')
                                   stc.pop();
                            else if(s[i] == '}' && stc.top() == '{')
                                   stc.pop();
                            else if(s[i] == ']' && stc.top() == '[')
                                   stc.pop();
                            else 
                                    return false;
                            
                    }
                            
            }
            return stc.empty();
    }
};