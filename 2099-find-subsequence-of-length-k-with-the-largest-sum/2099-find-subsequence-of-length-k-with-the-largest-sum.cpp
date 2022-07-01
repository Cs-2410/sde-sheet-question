// class Solution {
// public:
//     vector<int> maxSubsequence(vector<int>& nums, int k) {
//        if (k == nums.size())
//         return nums;
//             priority_queue<int> pq;
//             for(int i = 0; i < nums.size(); i++)
//                     pq.push(nums[i]);
//             vector<int> ans;
//             for(int i = 0; i < k; i++){
//                     ans.push_back(pq.top());
//                     pq.pop();
//             }
//          reverse(ans.begin() , ans.end());
//             return ans;           
            
//     }
// };
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
       if (k == nums.size())
        return nums;
            priority_queue<pair<int,int>> pq;
            for(int i = 0; i < nums.size(); i++)
                    pq.push(make_pair(nums[i],i));
            vector<int> ans;
            priority_queue<pair<int,int>> pq1;
            for(int i = 0; i < k; i++){
                    pq1.push(make_pair(pq.top().second,pq.top().first));
                    pq.pop();
            }
            while(!pq1.empty())
            {
                    ans.push_back(pq1.top().second);
                    pq1.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;           
            
    }
};