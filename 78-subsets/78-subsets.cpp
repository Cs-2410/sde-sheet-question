class Solution {
private:
void solve(vector<int>& nums , int in , vector<int> out , vector<vector<int>>& ans){
                if(in >= nums.size()){
                        ans.push_back(out);
                        return;
                }
                
        solve(nums , in + 1, out , ans);
        
        int el = nums[in];
        out.push_back(el);
        solve(nums , in + 1 , out , ans);
        }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
            vector<int> out;
            int in = 0;
           solve(nums, in , out , ans);
            return ans;
    }
};