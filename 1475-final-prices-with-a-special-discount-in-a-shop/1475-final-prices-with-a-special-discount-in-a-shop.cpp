class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
            stack<int> stk;
        vector<int> ans(n);
            for(int i = n-1; i >= 0; i--){
                    while((!stk.empty()) && (prices[i] < stk.top()))
                            stk.pop();
                    if(stk.empty())
                            ans[i] = prices[i];
                    else
                            ans[i] = prices[i]-stk.top();
                    stk.push(prices[i]);
            }
            return ans;
    }
};