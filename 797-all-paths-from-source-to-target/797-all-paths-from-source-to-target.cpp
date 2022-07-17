class Solution {
public:
        vector<int> level;
       vector<vector<int>> ans;
   void dfs(vector<vector<int>>& graph , vector<int>& vis , int node){
           
           level.push_back(node);
           if(node==graph.size()-1){
                   ans.push_back(level);
                   level.pop_back();
                   return;
           }
           vis[node] = 1;
           for(auto it:graph[node]){
                   if(!vis[it]){
                           dfs(graph , vis , it);
                   }
           }
           vis[node]=0;
           level.pop_back();
   }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
            vector<int> vis(graph.size(),0);
            
                            dfs(graph , vis , 0);
        return ans;
    }
};