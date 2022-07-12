class Solution {
public:
         bool isBinarySearchHelpful(vector<int>& nums, int start, int element) {
        return nums[start] != element;
    }
    bool search(vector<int>& nums, int target) {
        int low = 0;
            int high = nums.size()-1;
            while(low <= high){
                    int mid = low + (high-low)/2;
                    if(target == nums[mid]) return true;
                    if (!isBinarySearchHelpful(nums, low, nums[mid])) {
                low++;
                continue;
            }
                    if(nums[low] <= nums[mid]){
                            if((target >= nums[low])&&(target <= nums[mid]))
                                    high = mid;
                            else
                                    low = mid+1;
                    }
                    else
                        if((target >= nums[mid])&&(target <= nums[high]))
                                    low = mid+1;
                            else
                                    high = mid;    
                    
            }
             return false;
    }
};