class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
            int MOD=1e9+7;
            int n=arr.size();
            stack<pair<int,int>> stk;
            vector<int> left(n,-1);
            vector<int> right(n,-1);
            for(int i=0;i<n;i++){
                    while(!stk.empty() && stk.top().first>=arr[i])
                            stk.pop();
                    if(!stk.empty())
                            left[i]=stk.top().second;
                    stk.push(make_pair(arr[i],i));
            }
            while(!stk.empty()) stk.pop();
            for(int i=n-1;i>=0;i--){
                    while(!stk.empty() && stk.top().first>arr[i])
                            stk.pop();
                    if(!stk.empty())
                            right[i]=stk.top().second;
                    stk.push(make_pair(arr[i],i));
            }
            int sum=0;
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
                    long long length = (ll%MOD * rr%MOD) % MOD;
                    long long num=arr[i];
                    long long k=(length%MOD*num%MOD)%MOD;
                    sum=(sum%MOD + (k%MOD))%MOD;
                    // cout<<ll<<" "<<rr<<" "<<sum<<endl;
            }
            return sum;
    }
};