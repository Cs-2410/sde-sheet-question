class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<int> stc;
            
            for(int i = 0; i < s.size(); i++){
                    if(s[i] == '(')
                            stc.push(i);
                    else if(s[i] == ')'){
                            if(!stc.empty())
                                    stc.pop();
                                    
                                            
                           else 
                                   s[i] = '*';
                    }
            }
            
                    while(!stc.empty()){
                            s[stc.top()] = '*';
                            stc.pop();
                    }
            s.erase(remove(s.begin(), s.end(), '*'), s.end());
            return s;
    }
};