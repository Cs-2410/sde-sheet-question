class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans;
            priority_queue<int> pq;
            for(int  i = 0; i < nums.size(); i++)
                    pq.push(-nums[i]);
            while(!pq.empty()){
               int temp = 0;
                    temp = -pq.top();
                 ans.push_back(temp);
                    pq.pop();
 }
            return ans;
    }
};