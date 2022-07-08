class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k=2;
        vector<int> arr(2*k,INT_MIN);
        for(int i=0;i<prices.size();i++){
                for(int j=0;j<2*k;j++){
                        int temp=0;
                        if(j>0) temp=arr[j-1];
                        if(j%2==0) temp -= prices[i];
                        else temp += prices[i];
                        arr[j]=max(arr[j],temp);
                }
        }
        int ans=0;
        for(int i=1;i<2*k;i+=2)
                ans=max(ans,arr[i]);
        return ans;
    }
};