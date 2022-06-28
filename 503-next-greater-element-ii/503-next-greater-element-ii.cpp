class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
            vector<int> mp(nums.size() , -1);
            stack<int> stc;
            int flag = INT_MIN;
            int pos;
            for(int i =0; i < nums.size(); i++){
                    if(flag < nums[i]){
                            flag = nums[i];
                           pos = i;
                    }
            }  
            mp[pos] = -1;
            for(int i = pos; i >= 0; i--){
                    while(!stc.empty() && stc.top() <= nums[i]){
                            stc.pop();
                    }
                    if(stc.empty())
                            mp[i] = -1;
                    else
                            mp[i] = stc.top();
                    stc.push(nums[i]);
            }
            for(int i = nums.size()-1; i > pos ; i--){
                    while(!stc.empty() && stc.top() <= nums[i]){
                            stc.pop();
                    }
                    if(stc.empty())
                            mp[i] = -1;
                    else
                            mp[i] = stc.top();
                    stc.push(nums[i]);
            }
         return mp;   
            
    }
};