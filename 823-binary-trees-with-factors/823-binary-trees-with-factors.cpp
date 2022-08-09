class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int,long long> mp;
            sort(arr.begin(),arr.end());
            
            for(int i = 0; i < arr.size(); i++){
                    mp[arr[i]]++;
            }
            
            for(int i = 1; i < arr.size(); i++){
                    long long count = 0;
                    for(int j = 0; j < i; j++){
                            if(arr[i]%arr[j]==0){
                            if(mp.find(arr[i]/arr[j])!=mp.end()){
                                    count+=mp.find(arr[j])->second*mp.find(arr[i]/arr[j])->second;
                            }
                    }
                    }
                    mp.find(arr[i])->second+=count;
            }
            long long sum = 0;
            for(auto it:mp){
                    sum+= it.second;
            }
            return sum%1000000007;
    }
};