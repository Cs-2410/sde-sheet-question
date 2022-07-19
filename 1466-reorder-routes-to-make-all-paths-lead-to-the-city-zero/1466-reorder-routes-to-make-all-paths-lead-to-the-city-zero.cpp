class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
            // vector<int>t(n,0);
            // vector<vector<int>> adj(n,t);
            map<int , vector<int>> adj,back;
            for(auto edge:connections){
                    adj[edge[0]].push_back(edge[1]);
                    back[edge[1]].push_back(edge[0]);
            }
            vector<int> vis(n,0);
            queue<int> q;
            q.push(0);
            int count=0;
            while(!q.empty()){
                    int node=q.front();
                    // int par=q.front().second;
                    q.pop();
                    vis[node] = 1;
                    for(auto it:adj[node]){
                            // if(it!=par){
                            if(!vis[it]){
                                     count++;
                                    q.push(it);
                            }             
                    }
                    for(auto ele:back[node]){
                            if(!vis[ele])
                                    q.push(ele);
                    }
            }
            return count;
    }
};