class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
            int n = arr.size();
            vector<int> dp (n , -1);
            for(int i=n-1;i>=0;i--){
                    int maxEle=INT_MIN;
                    int index=i;
                    while(index<n && (index-i)<k){
                            maxEle=max(maxEle,arr[index]);
                            int temp = (index-i+1)*maxEle;
                            if(index+1<n) temp+=dp[index+1];
                            dp[i]=max(dp[i],temp);
                            index++;
                    }
            }
            return dp[0];
    }
};