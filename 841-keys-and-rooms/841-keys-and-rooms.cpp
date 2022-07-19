class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
            int n=rooms.size();
            // map<int , vector<int>> adj;
            // for(int i = 0; i < n; i++){
            //         for(auto ele:rooms[i])
            //         adj[i].push_back(ele);
            // }
            map<int,int> bfs;
            for(int i = 1; i < n; i++)
                    bfs[i]++;
            vector<int> vis(n , 0);
            // if(!vis[i]){
                            queue<int> q;
                            q.push(0);
                            vis[0]=1;
                            while(!q.empty()){
                                    int node = q.front();
                                    q.pop();
                                    bfs.erase(node);
                                    for(int it:rooms[node]){
                                           if(!vis[it]) q.push(it);
                                            vis[it] = 1;
                                    }
                            }
            
            if(bfs.size() == 0){
                    return true;
            }
         else
                 return false;
    }
};