class Solution {
public:
        bool dfs(int node, vector<int>& vis,vector<int>& dfsvis,vector<vector<int>>& graph,vector<int>& check){
                vis[node]=1;
                dfsvis[node]=1;
                for(auto it:graph[node]){
                        if(!vis[it]){
                               if(dfs(it,vis,dfsvis,graph,check))
                                // check[node]=1;
                                return check[node]=1;
                        }
                        else if(dfsvis[it]){
                                // check[node]=1;
                                return check[node]=1;
                        }
                }
                dfsvis[node] = 0;
                return false;
        }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       int n = graph.size();
            vector<int> vis(n,0);
            vector<int> dfsvis(n,0);
            vector<int> check(n,0);
            for(int i = 0; i < n; i++){
                    if(!vis[i]){
                            dfs(i,vis,dfsvis,graph,check);
                    }
            }
            vector<int> ans;
            for(int i = 0; i < n; i++){
                    if(!check[i])
                        ans.push_back(i);
            }
            return ans;
    }
};