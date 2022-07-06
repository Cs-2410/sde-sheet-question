class Solution {
public:vector<int> ans;
        vector<int> par;
        int find(int a){
                if(par[a] == a)
                        return a;
                par[a] = find(par[a]);
                return par[a];
        }
        void solve(int x , int y){
                int i = find(x);
                int j = find(y);
                if(i == j){
                      ans.clear();
                      ans.push_back(x);
                      ans.push_back(y);
                      return;
                }
               par[j] = i; 
           }
        
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
          int n = edges.size();
              
            par.resize(n+1);
            for(int i = 0; i < par.size(); i++)
              par[i]=i;
            for(auto ele : edges){
                    solve(ele[0],ele[1]);
            }
           return ans; 
    }
};