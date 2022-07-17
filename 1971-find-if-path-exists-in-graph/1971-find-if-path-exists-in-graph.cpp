class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        map<int ,vector<int>> adj;
            for(auto ele:edges){
                    adj[ele[0]].push_back(ele[1]);
                    adj[ele[1]].push_back(ele[0]);
            }
          vector<bool> vis(n,0);
           queue<int> q;
            vis[source] = 1;
            q.push(source);
                     while(!q.empty()){
                        int node = q.front();
                             // cout<<node<<endl;
                             q.pop();
                             if(node == destination) return true;
                             for(auto it:adj[node]){
                                     if(!vis[it]){
                                             q.push(it);
                                             vis[it] = 1;
                                     }
                             }
                            
                            }
            
                    
            return false;
            
    }
};