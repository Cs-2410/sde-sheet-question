class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(256,-1);
            int low = 0, high =0;
            int n = s.size();
            int len = 0;
            while(high < n){
                     low = max(map[s[high]] + 1, low);    
       map[s[high]] = high;
        len = max(len , high - low + 1);
                       high++;
                    
            }
            return len;
    }
};