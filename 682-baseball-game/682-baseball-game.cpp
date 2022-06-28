class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> stc;
            int ans = 0;
            for(int i = 0; i < ops.size(); i++){
                    if(ops[i] == "C")
                            stc.pop();
                    else if(ops[i] == "D"){
                            int d = 2*stc.top();
                            stc.push(d);
                    }
                    else if(ops[i] == "+"){
                            int a = stc.top();
                            stc.pop();
                            int b = stc.top();
                            stc.push(a);
                            stc.push(a+b);
                    }
                    else
                            stc.push(stoi(ops[i]));
            }
            while(!stc.empty()){
                    ans += stc.top();
                    stc.pop();
            }
            return ans;
    }
};