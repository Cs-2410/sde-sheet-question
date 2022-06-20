class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
            int m = -1;
            for(int i = 0; i < candies.size(); i++)
                    m = max(m , candies[i]);
              for(int i = 0; i < candies.size(); i++){
                      if(m <= (candies[i] + extraCandies))
                           ans.push_back(true);
                      else 
                            ans.push_back(false);       
              }
            return ans;
    }
};