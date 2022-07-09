class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
            int n = nums.size();
            map<int , int> mp;
            priority_queue<pair<int , int>> pq;
            vector<int> ans;
            for(int i = 0; i < n; i++){
                   mp[nums[i]]++;
            }
            
            for(auto ele : mp){
                    pq.push(make_pair(ele.second , ele.first));
            }
            while(k > 0){
                    // cout<<pq.top().first<<" "<<pq.top().second<<endl;
                    
                        ans.push_back(pq.top().second);
                            pq.pop();
                            k--;
                    
            }
            return ans;
    }
};