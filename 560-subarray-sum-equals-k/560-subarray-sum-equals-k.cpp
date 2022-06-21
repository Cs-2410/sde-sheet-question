class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
            if(n == 0)
                    return 0;
            unordered_map<int , int> mp;
            int sum , count , i;
            sum = count = i = 0;
            
            while(i < n){
                    sum += nums[i];
                    if(sum == k)
                            count++;
                    if(mp.find(sum - k) != mp.end())
                            count += mp[sum - k];
                    mp[sum] += 1;
                    i++;
            }
            return count;
    }
};