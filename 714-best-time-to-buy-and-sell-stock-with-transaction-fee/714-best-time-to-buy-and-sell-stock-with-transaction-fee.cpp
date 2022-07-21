class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
            vector<int> front1(2,0);
            vector<int> curr(2,0);
            for(int idx = n-1; idx >= 0; idx--){
                    curr[1] = max(front1[1],-prices[idx]+front1[0]);
                    curr[0] = max(front1[0],-fee+prices[idx]+front1[1]);
                    front1 = curr;
            }
           return curr[1]; 
    }
};