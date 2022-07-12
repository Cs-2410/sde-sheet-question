class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int max_num = nums[0];
            int pos = 0;
            for(int i = 1; i < nums.size()-1; i++){
                    if((nums[i] > nums[i-1])&&(nums[i]>nums[i+1])){
                            max_num = max(max_num , nums[i]);
                            if(max_num == nums[i]) pos = i;                  
                    }
            }
            max_num = max(max_num , nums[nums.size()-1]);
            if(max_num == nums[nums.size()-1]) pos = nums.size()-1;
            return pos;
    }
};