class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int MOD=1e9+7;
            int n=nums.size();
            stack<pair<int,int>> stk;
            vector<int> left(n,-1);
            vector<int> right(n,-1);
            for(int i=0;i<n;i++){
                    while(!stk.empty() && stk.top().first>=nums[i])
                            stk.pop();
                    if(!stk.empty())
                            left[i]=stk.top().second;
                    stk.push(make_pair(nums[i],i));
            }
            while(!stk.empty()) stk.pop();
            for(int i=n-1;i>=0;i--){
                    while(!stk.empty() && stk.top().first>nums[i])
                            stk.pop();
                    if(!stk.empty())
                            right[i]=stk.top().second;
                    stk.push(make_pair(nums[i],i));
            }
            while(!stk.empty()) stk.pop();
            long long sum_min=0;
            for(int i=0;i<n;i++){
                    int ll,rr;
                    if(left[i]==-1)
                            ll=i+1;
                    else
                            ll=i-left[i];
                    if(right[i]==-1)
                            rr=n-i;
                    else
                            rr=right[i]-i;
                    long long length = (ll * rr) ;
                    long long num=nums[i];
                    long long k=(length*num);
                    sum_min=(sum_min + (k));
            }
            left.clear();
            right.clear();
            left.resize(n,-1);
            right.resize(n,-1);
            for(int i=0;i<n;i++){
                    while(!stk.empty() && stk.top().first<=nums[i])
                            stk.pop();
                    if(!stk.empty())
                            left[i]=stk.top().second;
                    stk.push(make_pair(nums[i],i));
            }
            while(!stk.empty()) stk.pop();
            for(int i=n-1;i>=0;i--){
                    while(!stk.empty() && stk.top().first<nums[i])
                            stk.pop();
                    if(!stk.empty())
                            right[i]=stk.top().second;
                    stk.push(make_pair(nums[i],i));
            }
            while(!stk.empty()) stk.pop();
            long long sum_max=0;
            for(int i=0;i<n;i++){
                    int ll,rr;
                    if(left[i]==-1)
                            ll=i+1;
                    else
                            ll=i-left[i];
                    if(right[i]==-1)
                            rr=n-i;
                    else
                            rr=right[i]-i;
                    long long length = (ll * rr);
                    long long num=nums[i];
                    long long k=(length*num);
                    sum_max=(sum_max + (k));
            }
            return sum_max-sum_min;
            
    }
};