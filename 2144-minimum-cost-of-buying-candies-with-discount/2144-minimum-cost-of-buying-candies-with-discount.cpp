class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin() , cost.end());
        reverse(cost.begin() , cost.end());
        int sum = 0;
            for(int i = 1 ; i <= cost.size() ;i++){
                    if(i%3 != 0)
                      sum += cost[i-1];       
            }
            return sum;
    }
};