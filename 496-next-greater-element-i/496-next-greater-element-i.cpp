class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int , int> mp;
            vector<int> ans;
            stack<int> stc;
            for(int i = nums2.size()-1; i >= 0; i--){
                    while(!stc.empty() && stc.top() <= nums2[i]){
                            stc.pop();
                    }
                    if(stc.empty())
                            mp[nums2[i]] = -1;
                    else
                            mp[nums2[i]] = stc.top();
                    stc.push(nums2[i]);
            }
            for(int i = 0; i < nums1.size(); i++){
                  ans.push_back(mp[nums1[i]]);  
            }
            return ans;
    }
};