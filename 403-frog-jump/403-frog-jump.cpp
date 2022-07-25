class Solution {
public:
    bool canCross(vector<int>& stones) {
        map<int , set<int>> mp;
            for(int i = 0; i < stones.size(); i++){
                    set<int> t;
                    mp[stones[i]]=t;
            }
            mp[stones[0]].insert(1);
             for(int i = 0 ; i < stones.size(); i++){
                     int curr = stones[i];
                     set<int> jumps = mp[curr];
                     for(auto jump:jumps){
                             int stone = curr+jump;
                             if(stone == stones[stones.size()-1])
                                     return true;
                             if(mp.find(stone)!=mp.end()){
                              if(jump-1 != 0){
                                     mp[stone].insert(jump-1);
                              }
                                      mp[stone].insert(jump);
                                      mp[stone].insert(jump+1);
                             }
                     }
             }
            return false;
    }
};