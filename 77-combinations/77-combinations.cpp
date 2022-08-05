class Solution {
public:
        vector<vector<int>> ans;
        vector<int> level;
        void solve(int n , int k,int idx){
                if(level.size()==k){
                        ans.push_back(level);
                        return ;
                }
                for(int i = idx; i <= n; i++){
                        level.push_back(i);
                        solve(n , k,i+1);
                        level.pop_back();
                }
                return ;
        }
    vector<vector<int>> combine(int n, int k) {
         if(n<k)return ans;
            solve(n , k,1);
            level.resize(0,k);
            return ans;
    }
};