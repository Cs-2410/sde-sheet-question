class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
            int high = nums.size()-1;
            int mid;
            if(!high) return nums[0];
            
            while(low < high){
                     mid = low + (high-low)/2;
                    if(nums[low] < nums[high]){
                            return nums[low];
                    }
                    else if(nums[mid] > nums[high])
                       low = mid+1;
                    else if(nums[mid] == nums[high])
                            low++;
                    else
                            high = mid;
            }
             return nums[low];
    }
};