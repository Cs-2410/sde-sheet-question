class Solution {
public:vector<int> dp;
        int func(vector<int>& days, vector<int>& costs,int index){
                if(index >=days.size())
                        return 0;
                if(dp[index] != -1)
                        return dp[index];
                int ans = INT_MAX;
                for(int i = 0; i < 3; i++){
                       int k = (i == 0)?1:(i == 1)?7:30;
                        int day = days[index] + k;
                        int j = index + 1;
                        int cost = INT_MAX;
                        while(j<days.size() && days[j] <day){
                                j++;
                        }
                        cost = func(days,costs,j)+costs[i];
                        ans = min(cost , ans);         
                }
                // cout<<index<<"  "<<ans<<endl;
              dp[index] = ans;
                return ans;
        }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
      dp.resize(days.size()+1 , -1);
            return func(days,costs,0);
    }
};