class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;
            map<int,int> mp;
            for(int i =0 ; i < nums.size(); i++){
                    mp[nums[i]]++;
            }
            priority_queue<pair<int,int>> pq;
            for(auto it:mp){
                    pq.push({-it.second,it.first});
            }
            while(!pq.empty()){
                    int k = -pq.top().first;
                    int level = pq.top().second;
                    while(k>0){
                    ans.push_back(level);
                            k--;
                    }
                    pq.pop();
            }
            return ans;
    }
};