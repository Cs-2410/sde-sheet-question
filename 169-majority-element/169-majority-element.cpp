class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
            int element = 0;
            for (int n : nums){
                    if (count == 0){
                            element = n;
                    }
                    if (n == element) 
                            count += 1;
                    else 
                            count -= 1;
            }
            return element;
    }
};