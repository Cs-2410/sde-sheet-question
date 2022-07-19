class Solution {
public:
        #define ll long long
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<ll , ll> mp;
            for(auto ele:roads){
                    mp[ele[0]]++;
                    mp[ele[1]]++;
            }
            priority_queue<pair<ll , ll>> pq;
            for(ll i = 0; i < mp.size(); i++)
                    pq.push({mp[i] , i});
            ll val = n;
            while(!pq.empty()){
               ll  t = pq.top().second;
                    mp[t] = val;
                    val--;
                    pq.pop();
            }
            ll sum = 0;
            for(auto ele:roads){
                    sum = sum+mp[ele[0]]+mp[ele[1]];
            }
            return sum;
    }
};