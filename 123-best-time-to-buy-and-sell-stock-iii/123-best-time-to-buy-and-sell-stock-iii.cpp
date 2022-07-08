class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a=INT_MAX,b=INT_MIN,c=INT_MIN,d=INT_MIN;
        for(int i=0;i<prices.size();i++){
                a=min(a,prices[i]);
                b=max(b,prices[i]-a);
                c=max(c,b-prices[i]);
                d=max(d,c+prices[i]);
        }
        return max(b,max(0,d));
    }
};