class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
            int n = tokens.size();
            for(int i = 0; i < n; i++){
                     int c = 0;
                    
                            if(tokens[i] == "+"){
                                   int a = stk.top();
                                    stk.pop();
                                    int b = stk.top();
                                    stk.pop();
                                     b += a;
                                    stk.push(b);
                            }
                            else if(tokens[i] == "-"){
                                    int a = stk.top();
                                    stk.pop();
                                    int b = stk.top();
                                    stk.pop();
                                     b -= a;
                                    stk.push(b);
                            }
                            else if(tokens[i] == "*"){
                                    int a = stk.top();
                                    stk.pop();
                                    int b = stk.top();
                                    stk.pop();
                                     b *= a;
                                    stk.push(b);
                            }
                            else if(tokens[i] == "/"){
                                    int a = stk.top();
                                    stk.pop();
                                    int b = stk.top();
                                    stk.pop();
                                     b /= a;
                                    stk.push(b);
                            }
                            else {
                                    string str = tokens[i];
                                    c = stoi(str);
                                    stk.push(c);
                    
                            }
                   
                            }
            return stk.top();
    }
};