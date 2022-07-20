class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> indgree(n);
        vector<int>t(n,0);
            vector<vector<int>> adj(n,t);
            for(auto ele:roads){
                    indgree[ele[0]]++;
                    indgree[ele[1]]++;
                    adj[ele[0]][ele[1]]=1;
                    adj[ele[1]][ele[0]]=1;
            }
            int maxi = INT_MIN;
            for(int i= 0; i < n; i++){
                    int sum;
                    for(int j = i+1; j < n; j++){
                            sum = indgree[j] + indgree[i];
                            if(adj[i][j]==1)
                                    sum = sum-1;
                            maxi = max(sum , maxi); 
                    }
                    
            }
            return maxi;
    }
};