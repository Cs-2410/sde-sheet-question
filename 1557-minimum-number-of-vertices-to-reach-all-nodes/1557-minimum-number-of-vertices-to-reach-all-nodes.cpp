class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indgree(n);
            for(auto it:edges)
                    indgree[it[1]]++;
            vector<int> ans;
            for(int i = 0; i < n; i++){
                    if(indgree[i] == 0)
                            ans.push_back(i);
            }
            return ans;
    }
};