class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
            int zero=0,one=0;
            int start=0,end=0,n=nums.size(),ans=INT_MIN;
            while(end<n){
                    if(nums[end]==1)
                            one++;
                    else
                            zero++;
                    while(zero>k){
                          if(nums[start]==1) one--;
                          else zero--;
                          start++;  
                    }
                    ans=max(ans,zero+one);
                    end++;
            }
            return ans;
    }
};