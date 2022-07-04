class Solution {
public:
    vector<vector<int>> ans;
        vector<int> level;
        void solve(int k, int n, int index, int sum){
                // cout<<index<<" "<<sum<<endl;
           if(sum > n)
                   return ;
                
                
                
              if(sum == n){
                      // cout<<"Here";
                      if(level.size() == k)
                       ans.push_back(level);
                return ;
              }
                if(index > 9)
                        return ;
              for(int i=index; i<10;i++){
                        level.push_back(i);
                        sum += i;
                       solve(k , n ,i+1 ,sum);
                       level.pop_back();
                       sum -= i;
                }
        }
        vector<vector<int>> combinationSum3(int k, int n) {
        
            if(n == 0)
                    return ans;
            
            solve(k , n ,1 ,0);
            return ans;
    }
};