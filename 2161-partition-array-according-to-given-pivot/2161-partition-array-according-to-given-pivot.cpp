class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // int  i = 0, j = 1, n = nums.size();
        //  while(i<n && j<n){
        //           if ((nums[i]>=pivot && nums[j]<pivot)||(nums[i]>pivot && nums[j]==pivot)){
        //                  swap(nums[i],nums[j]);
        //                 if(i>0) i--,j--;
        //          }
        //          // else if(nums[i]>pivot && nums[j]==pivot){
        //          //         swap(nums[i],nums[j]);
        //          //         if(i>0) i--,j--;
        //          // }
        //          else {
        //                  i++,j++;
        //          }
        //  }
        //     return nums;
    //         stable_partition(stable_partition(begin(n), end(n), [&](int n){ return n < p; }), end(n), [&](int n){ return n == p; });
    // return n;
            vector<int> ans;
            for(int i = 0; i < nums.size(); i++){
                    if(nums[i]<pivot) ans.push_back(nums[i]);
            }
            for(int i = 0; i < nums.size(); i++){
                    if(nums[i]==pivot) ans.push_back(nums[i]);
            }
            for(int i = 0; i < nums.size(); i++){
                    if(nums[i]>pivot) ans.push_back(nums[i]);
            }
            return ans;
    }
};