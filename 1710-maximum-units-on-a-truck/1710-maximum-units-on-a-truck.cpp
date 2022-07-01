class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pair<int , int>> pq;
            for(int i = 0; i < boxTypes.size(); i++)
                  pq.push(make_pair(boxTypes[i][1] , boxTypes[i][0])); 
            int sum = 0;
            while(truckSize > 0 && !pq.empty()){
                    int count=min(truckSize,pq.top().second);
                    sum += count*pq.top().first;
                    truckSize -= count;
                    pq.pop();
            }
           return sum; 
    }
};