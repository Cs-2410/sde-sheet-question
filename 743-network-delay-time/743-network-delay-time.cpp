class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int , int>> adj[n+1];
            for(auto ele:times)
                    adj[ele[0]].push_back(make_pair(ele[1] , ele[2]));
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            vector<int> dis(n+1,INT_MAX);
            dis[k] = 0;
            pq.push(make_pair(0,k));
            
            while(!pq.empty()){
                    int curr_dis = pq.top().first;
                    int prev = pq.top().second;
                    pq.pop();
                    for(auto it:adj[prev]){
                            int next = it.first;
                            int next_dis = it.second;
                            if(dis[next] > curr_dis + next_dis){
                                    dis[next] = curr_dis+next_dis;
                                    pq.push(make_pair(dis[next],next));
                            }
                    }
            }
            int ans = INT_MIN;
            for(int i = 1; i <= n; i++){
                    if(dis[i]==INT_MAX) return -1;
                    if(ans < dis[i])
                            ans = dis[i];
            }
            return ans;
    }
};