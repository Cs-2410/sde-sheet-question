class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
            int high = nums.size()-1;
            while(low <= high){
                    int mid = low + (high-low)/2;
                    if(target == nums[mid]) return mid;
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
             return -1;
            
            
            // if((target > nums[0])&&(target <= nums[highest])){
            //         low = 0;
            //         high = highest;
            //         while(low < high){
            //              int mid = low + (high-low)/2;
            //         if(target > nums[mid])
            //                 low = mid;
            //         else
            //                 high = mid+1;   
            //         }
            //       return low;  
            // }
            // else if(target < nums[0]){
            //         low = highest+1;
            //         high = nums.size();
            //         while(low < high){
            //              int mid = low + (high-low)/2;
            //         if(target > nums[mid])
            //                 low = mid;
            //         else
            //                 high = mid+1;   
            //         }
            //       return low;  
            // } 
            //         return -1;
    }
};