class Solution {
public:
        int solve(vector<int>& nums, int target,int low , int high){
                if(low <= high) {
                
                int mid = low + (high-low)/2;
                if(nums[mid]==target){
                        int k = solve(nums,target,low,mid-1);
                        if(k == -1) return mid;
                        else
                                return k;
                }
                if(nums[mid] > target){
                        return solve(nums,target,low,mid-1);
                }
               else 
             return solve(nums,target,mid+1,high);
                      }
                return -1;
                
        }
        int solve2(vector<int>& nums, int target,int low , int high){
                if(low <= high) 
               { 
                int mid = low + (high-low)/2;
                if(nums[mid]==target){
                        int k = solve2(nums,target,mid+1,high);
                        if(k == -1) return mid;
                        else
                                return k;
                }
              else if(nums[mid] > target){
                        return solve2(nums,target,low,mid-1);
              }
               else 
             return solve2(nums,target,mid+1,high);
                      }
        
                return -1;   
                
        }
        
    vector<int> searchRange(vector<int>& nums, int target) {
        int pos_left = solve(nums,target,0,nums.size()-1);
            
         int pos_right = solve2(nums,target,0,nums.size()-1);
            vector<int> ans;
            ans.push_back(pos_left);
            ans.push_back(pos_right);
            return ans;
    }
};