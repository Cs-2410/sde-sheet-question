class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
           vector<vector<int>> ans;
            if(k > points.size())
                   return ans;
            
            priority_queue<pair<long long int , pair<int , int>>> pq;
            for(int i = 0; i < points.size(); i++){
            long long int sq = ((points[i][0]*points[i][0])+(points[i][1]*points[i][1]));
                    pq.push(make_pair(-sq , make_pair(points[i][0] , points[i][1])));
                    }
            vector<int> level;
            while(k > 0){
                 level.push_back(pq.top().second.first);
                 level.push_back(pq.top().second.second);
                 ans.push_back(level);
                    pq.pop();
                    k--;
                    level.clear();
            }
            return ans;
    }
};