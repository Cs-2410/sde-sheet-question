class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int , int>> stc;
            vector<int> ans;
           
            for(int i = temperatures.size() - 1; i >= 0; i--){
                    while(!stc.empty() && stc.top().first <= temperatures[i])
                            stc.pop();
                    if(stc.empty())
                            ans.push_back(0);
                    else 
                            ans.push_back(stc.top().second - i);
                    stc.push({ temperatures[i], i });
            }
            reverse(ans.begin(),ans.end());
            return ans;
     }
};