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
                                    // cout<<b<<"bb"<<endl;
                                    stk.push(b);
                            }
                            else if(tokens[i] == "-"){
                                    int a = stk.top();
                                    stk.pop();
                                    int b = stk.top();
                                    stk.pop();
                                    // cout<<b<<"bb"<<endl;
                                     b -= a;
                                    stk.push(b);
                            }
                            else if(tokens[i] == "*"){
                                    int a = stk.top();
                                    stk.pop();
                                    int b = stk.top();
                                    stk.pop();
                                     b *= a;
                                    // cout<<b<<"bb"<<endl;
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
       //          for ( int i = str.length() -1 ; i >= 0 ; i-- ) {
       //                int power = str.length() - i -1;
       //                c += (std::pow( 10.0,  power) * (str[i] - '0'));
       // }
                    
                                    stk.push(c);
                    
                            }
                    // cout<<c<<" "<<endl;
                            }
            return stk.top();
    }
};