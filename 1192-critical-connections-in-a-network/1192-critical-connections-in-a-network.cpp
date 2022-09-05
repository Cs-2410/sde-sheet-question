class Solution {
public:
        vector<vector<int>> ans;
void dfs(int node, int parent, vector<int> &vis,vector<int> &tin,vector<int> &low, int &timer, map<int,vector<int>> &adj){
        vis[node]=1;
        low[node]=tin[node]=timer++;
        for(auto it:adj[node]){
                if(it==parent) continue;
                
                if(!vis[it]){
                        dfs(it,node,vis,tin,low,timer,adj);
                        low[node]=min(low[node],low[it]);
                        vector<int> level;
                        if(low[it]>tin[node]){
                                level.push_back(node);
                                level.push_back(it);
                        }
                        if(level.size()>0) ans.push_back(level);
                }
                else
                        low[node]=min(low[node],tin[it]);
        }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        map<int ,vector<int>> adj;
            for(auto ele:connections){
                    adj[ele[0]].push_back(ele[1]);
                    adj[ele[1]].push_back(ele[0]);
            }
            vector<int> tin(n,-1);
            vector<int> low(n,-1);
            vector<int> vis(n,0);
            int timer = 0;
            for(int i = 0; i <n; i++){
                    if(!vis[i]){
                            dfs(i,-1,vis,tin,low,timer,adj);
                    }
            }
            return ans;
    }
};