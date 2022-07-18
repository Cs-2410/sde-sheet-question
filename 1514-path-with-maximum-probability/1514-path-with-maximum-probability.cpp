class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int , double>> adj[n];
            for(int i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].push_back(make_pair(edges[i][1] , succProb[i]));
            adj[edges[i][1]].push_back(make_pair(edges[i][0] , succProb[i]));
        }
            queue<int> pq;
            vector<double> dis(n,0);
            dis[start] = 1;
            pq.push(start);
            
            while(!pq.empty()){
                    // double curr_dis = pq.top().first;
                    int prev = pq.front();
                    pq.pop();
                    for(auto it:adj[prev]){
                            int next = it.first;
                            double next_dis = it.second;
                            if(dis[next] < dis[prev]*next_dis){
                                dis[next] =  dis[prev]*next_dis;
                                    pq.push(next);
                            }
                        }        
                      }
            return dis[end];
    }
};