class Solution {
public:
        map<int,int> dp;
        int func(map<int,int>& mp, int n){
                if(n<=0) return 0;
                if(dp.find(n)!=dp.end()) return dp[n];
                return dp[n]=max(func(mp,n-1),func(mp,n-2)+mp[n]);
        }
    int deleteAndEarn(vector<int>& nums) {
        
            map<int,int> mp;
            int max_num=0;
            for(int num:nums){
                    mp[num]+=num;
                    max_num=max(max_num,num);
            }
            return func(mp,max_num);
            
    }
};