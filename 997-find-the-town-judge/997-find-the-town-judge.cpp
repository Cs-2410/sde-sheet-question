class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int , int> mp;
            for(int i = 1; i <= n; i++)
                    mp[i] = 1;
                   
            for(int i = 0; i < trust.size();i++){
               mp[trust[i][1]]++;
                    int flag = trust[i][0];
                    
                    mp.erase(flag);
        }
            int ans=-1;
          for(auto it:mp){
                  if(it.second == n)
                          ans = it.first;
          }
            
           
            return ans;
    }
};