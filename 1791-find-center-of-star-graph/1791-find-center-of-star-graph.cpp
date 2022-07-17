class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
      map<int ,int> adj;
            for(auto ele:edges){
                    adj[ele[0]]++,adj[ele[1]]++;
            }
            int size = edges.size();
            int ans = 0;
            for(auto& itr:adj){ 
                    if(size == itr.second)
                            ans = itr.first; 
            }
            return ans;
    }
};