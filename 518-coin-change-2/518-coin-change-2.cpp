// class Solution {
// private:
//         int solve(int amount, vector<int>& coins ,map<int , int>& mp){
//                 if(amount < 0)
//                         return 0;
//                 if(amount == 0)
//                         return 1;
//                 if (mp.find(amount) != mp.end())
//                         return mp[amount];
//                 int ans = 0;
//                 for(int i = 0; i < coins.size(); i++){
//                         ans += solve(amount - coins[i] , coins , mp);
                        
//                 }
//                 mp[amount] = ans;
                
//                 return ans;
//         }
// public:
//     int change(int amount, vector<int>& coins) {
//          map<int , int> mp;
//          int ways = solve(amount , coins , mp);
//          return ways;
//     }
// };

class Solution {
private:
        int solve(int amount, vector<int>& coins,int index ,map<pair<int,int> , int>& mp){
                if(amount < 0)
                        return 0;
                if(amount == 0)
                        return 1;
                if(index>=coins.size()) return 0;
                if (mp.find(make_pair(amount,index)) != mp.end())
                        return mp[make_pair(amount,index)];
                int ans = 0;
                ans += solve(amount - coins[index] , coins,index , mp);
                ans += solve(amount, coins , index+1 , mp);
                mp[make_pair(amount,index)] = ans;
                return ans;
        }
public:
    int change(int amount, vector<int>& coins) {
         map<pair<int,int> , int> mp;
         sort(coins.begin(),coins.end());
         reverse(coins.begin(),coins.end());
         int ways = solve(amount , coins, 0 , mp);
         return ways;
    }
};