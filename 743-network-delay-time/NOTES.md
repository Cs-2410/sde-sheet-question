```***Using (DFS + stack)
and use of toposort;*
```
class Solution {
public:
int ans = INT_MIN;
void findtoposort(int node , vector<int>& vis , stack<int>& stk, map<int ,vector<pair<int , int>>>& adj){
vis[node] = 1;
for(auto it:adj[node]){
if(!vis[it.first])
findtoposort(it.first , vis , stk , adj);
}
stk.push(node);
}
void dfs(map<int , vector<pair<int , int>>>& adj , int N , int src){
vector<int> vis(N ,0);
stack<int> stk;
for(int i = 1; i <= N ; i++){
if(!vis[i])
findtoposort(i , vis,stk,adj);
}
int dist[N];
for(int i = 1; i<= N;i++)
dist[i] = INT_MAX;
dist[src] = 0;
while(!stk.empty()){
int node = stk.top();
stk.pop();
if(dist[node] != INT_MAX){
for(auto it:adj[node]){
if(dist[node] + it.second < it.second)
dist[it.first] = dist[node] + it.second;
}
}
}
for(int i = 1; i <= N; i++){
if(dist[i]>ans)
ans = dist[i];
}
```
}
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
map<int , vector<pair<int , int>>> adj;
for(auto ele:times)
adj[ele[0]].push_back({ele[1] , ele[2]});
dfs(adj , n , k);
return (ans == INT_MIN)?-1:ans;
}
};``
```
​