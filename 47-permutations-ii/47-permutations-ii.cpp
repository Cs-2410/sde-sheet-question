class Solution {
public:
        vector<vector<int>> ans;
        map<vector<int>,int> mp;
        void solve(vector<int> nums ,int index){
                if(index==(nums.size()-1)){
                        if(mp.find(nums)==mp.end()){
                                mp[nums]=1;
                                ans.push_back(nums);
                        }
                        return;
                }
                for(int i = index; i < nums.size(); i++){
                        if(i>index && nums[i]==nums[i-1]) continue;
                        swap(nums[i] ,nums[index]);
                        
                        solve(nums , index+1);
                }
        }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       sort(nums.begin() , nums.end());
            solve(nums ,0);
            return ans;
    }
};